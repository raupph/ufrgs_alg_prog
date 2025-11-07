#!/bin/bash
# Automatic raylib setup script for multiple platforms
# This script automatically detects the platform and installs raylib

set -e  # Exit on any error

echo "=========================================="
echo "   Raylib Automatic Setup Script"
echo "=========================================="

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Detect platform
detect_platform() {
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        PLATFORM="linux"
        print_status "Detected platform: Linux"
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        PLATFORM="macos"
        print_status "Detected platform: macOS"
    elif [[ "$OSTYPE" == "cygwin" ]] || [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "win32" ]]; then
        PLATFORM="windows"
        print_status "Detected platform: Windows"
    else
        print_warning "Unknown platform: $OSTYPE"
        PLATFORM="unknown"
    fi
}

# Install dependencies for Linux
install_linux_deps() {
    print_status "Installing dependencies for Linux..."
    
    # Detect package manager
    if command -v apt >/dev/null 2>&1; then
        print_status "Using apt package manager..."
        sudo apt update
        sudo apt install -y build-essential git cmake
        sudo apt install -y libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev
        
        # Try to install raylib from package manager first
        if sudo apt install -y libraylib-dev 2>/dev/null; then
            print_success "Raylib installed from package manager!"
            return 0
        else
            print_warning "Raylib not available in package manager, will build from source..."
        fi
        
    elif command -v pacman >/dev/null 2>&1; then
        print_status "Using pacman package manager..."
        sudo pacman -Sy --needed base-devel git cmake
        sudo pacman -Sy --needed alsa-lib libx11 libxrandr libxi mesa glu libxcursor libxinerama
        
        if sudo pacman -S --needed raylib 2>/dev/null; then
            print_success "Raylib installed from package manager!"
            return 0
        else
            print_warning "Raylib not available in package manager, will build from source..."
        fi
        
    elif command -v dnf >/dev/null 2>&1; then
        print_status "Using dnf package manager..."
        sudo dnf groupinstall -y "Development Tools"
        sudo dnf install -y git cmake
        sudo dnf install -y alsa-lib-devel libX11-devel libXrandr-devel libXi-devel mesa-libGL-devel mesa-libGLU-devel libXcursor-devel libXinerama-devel
        
        if sudo dnf install -y raylib-devel 2>/dev/null; then
            print_success "Raylib installed from package manager!"
            return 0
        else
            print_warning "Raylib not available in package manager, will build from source..."
        fi
        
    else
        print_error "No supported package manager found (apt, pacman, dnf)"
        return 1
    fi
    
    # Build from source if package manager installation failed
    build_raylib_from_source
}

# Install dependencies for macOS
install_macos_deps() {
    print_status "Installing dependencies for macOS..."
    
    # Check if Xcode command line tools are installed
    if ! command -v gcc >/dev/null 2>&1; then
        print_status "Installing Xcode command line tools..."
        xcode-select --install
        print_status "Please complete Xcode installation and run this script again."
        exit 1
    fi
    
    # Install Homebrew if not present
    if ! command -v brew >/dev/null 2>&1; then
        print_status "Installing Homebrew..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi
    
    # Install raylib via Homebrew
    print_status "Installing raylib via Homebrew..."
    brew install raylib
    print_success "Raylib installed successfully!"
}

# Install dependencies for Windows (MinGW/MSYS2)
install_windows_deps() {
    print_status "Setting up raylib for Windows..."
    
    if command -v pacman >/dev/null 2>&1; then
        # MSYS2 environment
        print_status "MSYS2 detected, installing raylib..."
        pacman -Sy --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-raylib
        print_success "Raylib installed successfully!"
    else
        print_warning "This script works best with MSYS2 on Windows."
        print_status "Please install MSYS2 from https://www.msys2.org/"
        print_status "Or download pre-built raylib from https://github.com/raysan5/raylib/releases"
        return 1
    fi
}

# Build raylib from source
build_raylib_from_source() {
    print_status "Building raylib from source..."
    
    # Create temporary directory
    TEMP_DIR=$(mktemp -d)
    cd "$TEMP_DIR"
    
    # Clone raylib
    print_status "Cloning raylib repository..."
    git clone https://github.com/raysan5/raylib.git
    cd raylib
    
    # Build raylib
    print_status "Building raylib..."
    mkdir build
    cd build
    cmake ..
    make -j$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
    
    # Install raylib
    print_status "Installing raylib..."
    sudo make install
    
    # Update library cache on Linux
    if [[ "$PLATFORM" == "linux" ]]; then
        sudo ldconfig
    fi
    
    # Cleanup
    cd "$HOME"
    rm -rf "$TEMP_DIR"
    
    print_success "Raylib built and installed successfully!"
}

# Test raylib installation
test_installation() {
    print_status "Testing raylib installation..."
    
    # Create test program
    cat > test_raylib.c << 'EOF'
#include "raylib.h"
int main() {
    InitWindow(400, 300, "Test");
    CloseWindow();
    return 0;
}
EOF
    
    # Try to compile test program
    if gcc test_raylib.c -o test_raylib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 2>/dev/null ||
       gcc test_raylib.c -o test_raylib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo 2>/dev/null ||
       gcc test_raylib.c -o test_raylib -lraylib -lopengl32 -lgdi32 -lwinmm 2>/dev/null; then
        print_success "Raylib installation test passed!"
        rm -f test_raylib.c test_raylib test_raylib.exe
        return 0
    else
        print_error "Raylib installation test failed!"
        rm -f test_raylib.c test_raylib test_raylib.exe
        return 1
    fi
}

# Main installation process
main() {
    detect_platform
    
    case "$PLATFORM" in
        "linux")
            install_linux_deps
            ;;
        "macos")
            install_macos_deps
            ;;
        "windows")
            install_windows_deps
            ;;
        *)
            print_error "Unsupported platform: $PLATFORM"
            print_status "Please install raylib manually from: https://github.com/raysan5/raylib"
            exit 1
            ;;
    esac
    
    # Test installation
    if test_installation; then
        echo ""
        echo "=========================================="
        print_success "Raylib setup completed successfully!"
        echo "=========================================="
        echo ""
        print_status "You can now use 'make' to compile your raylib projects"
        print_status "Available commands:"
        echo "  make          - Build project"
        echo "  make run      - Build and run project"
        echo "  make clean    - Clean build files"
        echo "  make help     - Show all available commands"
        echo ""
    else
        print_error "Setup completed but raylib test failed"
        print_status "Please check the installation manually"
        exit 1
    fi
}

# Run main function
main "$@"