# Cross-platform Makefile for raylib C programs
# Supports Linux, Windows (MinGW), macOS, and Web (Emscripten)

# Project configuration
PROJECT_NAME = ex1_executavel
SOURCE_FILE = pratica1.c

# Compiler configuration
CC ?= gcc
CFLAGS = -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces

# Detect platform
ifeq ($(OS),Windows_NT)
    PLATFORM = WINDOWS
    DETECTED_OS = Windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM = LINUX
        DETECTED_OS = Linux
    endif
    ifeq ($(UNAME_S),Darwin)
        PLATFORM = OSX
        DETECTED_OS = macOS
    endif
endif

# Platform-specific configurations
ifeq ($(PLATFORM),WINDOWS)
    # Windows (MinGW)
    EXT = .exe
    RAYLIB_LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
    RAYLIB_PATH ?= C:/raylib/raylib
    CFLAGS += -I$(RAYLIB_PATH)/src
    LDFLAGS += -L$(RAYLIB_PATH)/src
endif

ifeq ($(PLATFORM),LINUX)
    # Linux
    EXT = 
    # Try pkg-config first, fallback to manual linking
    PKG_CONFIG_RAYLIB = $(shell pkg-config --exists raylib && echo "yes" || echo "no")
    ifeq ($(PKG_CONFIG_RAYLIB),yes)
        RAYLIB_CFLAGS = $(shell pkg-config --cflags raylib)
        # Use --static for static libraries (raylib is usually static)
        RAYLIB_LIBS = $(shell pkg-config --libs --static raylib 2>/dev/null || pkg-config --libs raylib) 
        # Ensure we have the required libs even if pkg-config is incomplete
        ifeq ($(shell echo "$(RAYLIB_LIBS)" | grep -q "\-lGL" && echo "yes" || echo "no"),no)
            RAYLIB_LIBS += -lGL -lm -lpthread -ldl -lrt -lX11
        endif
    else
        RAYLIB_LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
        # Common raylib installation paths
        ifneq (,$(wildcard /usr/local/include/raylib.h))
            RAYLIB_CFLAGS = -I/usr/local/include
            LDFLAGS += -L/usr/local/lib
        else ifneq (,$(wildcard /usr/include/raylib.h))
            RAYLIB_CFLAGS = -I/usr/include
            LDFLAGS += -L/usr/lib
        endif
    endif
endif

ifeq ($(PLATFORM),OSX)
    # macOS
    EXT = 
    # Try pkg-config first, fallback to manual linking
    PKG_CONFIG_RAYLIB = $(shell pkg-config --exists raylib && echo "yes" || echo "no")
    ifeq ($(PKG_CONFIG_RAYLIB),yes)
        RAYLIB_CFLAGS = $(shell pkg-config --cflags raylib)
        RAYLIB_LIBS = $(shell pkg-config --libs raylib) -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
    else
        RAYLIB_LIBS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
        # Common raylib installation paths on macOS
        ifneq (,$(wildcard /usr/local/include/raylib.h))
            RAYLIB_CFLAGS = -I/usr/local/include
            LDFLAGS += -L/usr/local/lib
        else ifneq (,$(wildcard /opt/homebrew/include/raylib.h))
            RAYLIB_CFLAGS = -I/opt/homebrew/include
            LDFLAGS += -L/opt/homebrew/lib
        endif
    endif
endif

# Web target (Emscripten)
ifeq ($(TARGET),WEB)
    CC = emcc
    EXT = .html
    CFLAGS += -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB
    RAYLIB_LIBS = -s USE_GLFW=3 --shell-file minshell.html
    ifneq (,$(wildcard $(EMSDK)/upstream/emscripten/cache/sysroot/include/raylib.h))
        RAYLIB_CFLAGS = -I$(EMSDK)/upstream/emscripten/cache/sysroot/include
    endif
endif

# Default target
all: info $(PROJECT_NAME)

# Show build information
info:
	@echo "================================="
	@echo "  Raylib Cross-Platform Build"
	@echo "================================="
	@echo "Detected OS: $(DETECTED_OS)"
	@echo "Platform: $(PLATFORM)"
	@echo "Compiler: $(CC)"
	@echo "Target: $(PROJECT_NAME)$(EXT)"
	@echo "================================="

# Compile the project
$(PROJECT_NAME): $(SOURCE_FILE)
ifeq ($(V),1)
	@echo "Compile command:"
	@echo "$(CC) $(CFLAGS) $(RAYLIB_CFLAGS) $(SOURCE_FILE) -o $(PROJECT_NAME)$(EXT) $(LDFLAGS) $(RAYLIB_LIBS)"
	@echo ""
endif
	$(CC) $(CFLAGS) $(RAYLIB_CFLAGS) $(SOURCE_FILE) -o $(PROJECT_NAME)$(EXT) $(LDFLAGS) $(RAYLIB_LIBS)
	@echo ""
	@echo "✓ Build successful: $(PROJECT_NAME)$(EXT)"
ifeq ($(V),1)
	@echo "Used flags:"
	@echo "  CFLAGS: $(CFLAGS)"
	@echo "  RAYLIB_CFLAGS: $(RAYLIB_CFLAGS)"
	@echo "  LDFLAGS: $(LDFLAGS)"
	@echo "  RAYLIB_LIBS: $(RAYLIB_LIBS)"
endif
	@echo ""

# Web target
web:
	$(MAKE) TARGET=WEB $(PROJECT_NAME)

# Fix raylib pkg-config file
fix-raylib-pkgconfig:
	@echo "Fixing raylib pkg-config configuration..."
ifeq ($(PLATFORM),LINUX)
	@if [ -f /usr/local/lib/pkgconfig/raylib.pc ]; then \
		echo "Backing up original raylib.pc..."; \
		sudo cp /usr/local/lib/pkgconfig/raylib.pc /usr/local/lib/pkgconfig/raylib.pc.backup 2>/dev/null || true; \
		echo "Updating raylib.pc with proper dependencies..."; \
		sudo tee /usr/local/lib/pkgconfig/raylib.pc > /dev/null << 'EOF'; \
prefix=/usr/local\n\
exec_prefix=$${prefix}\n\
libdir=$${exec_prefix}/lib\n\
includedir=$${prefix}/include\n\
\n\
Name: raylib\n\
Description: A simple and easy-to-use library to enjoy videogames programming\n\
URL: https://github.com/raysan5/raylib\n\
Version: 5.5.0\n\
Libs: -L"$${libdir}" -lraylib\n\
Libs.private: -lGL -lm -lpthread -ldl -lrt -lX11\n\
Cflags: -I"$${includedir}"\n\
EOF \
		echo "✓ raylib.pc fixed successfully!"; \
	else \
		echo "raylib.pc not found at /usr/local/lib/pkgconfig/"; \
	fi
endif
ifeq ($(PLATFORM),OSX)
	@if [ -f /usr/local/lib/pkgconfig/raylib.pc ] || [ -f /opt/homebrew/lib/pkgconfig/raylib.pc ]; then \
		RAYLIB_PC_PATH=$$(find /usr/local /opt/homebrew -name "raylib.pc" 2>/dev/null | head -1); \
		if [ -n "$$RAYLIB_PC_PATH" ]; then \
			echo "Backing up original raylib.pc..."; \
			sudo cp "$$RAYLIB_PC_PATH" "$$RAYLIB_PC_PATH.backup" 2>/dev/null || true; \
			echo "Updating raylib.pc with proper dependencies..."; \
			sudo tee "$$RAYLIB_PC_PATH" > /dev/null << 'EOF'; \
prefix=/usr/local\n\
exec_prefix=$${prefix}\n\
libdir=$${exec_prefix}/lib\n\
includedir=$${prefix}/include\n\
\n\
Name: raylib\n\
Description: A simple and easy-to-use library to enjoy videogames programming\n\
URL: https://github.com/raysan5/raylib\n\
Version: 5.5.0\n\
Libs: -L"$${libdir}" -lraylib\n\
Libs.private: -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo\n\
Cflags: -I"$${includedir}"\n\
EOF \
			echo "✓ raylib.pc fixed successfully!"; \
		fi; \
	else \
		echo "raylib.pc not found"; \
	fi
endif

# Verify raylib installation
verify-raylib:
	@echo "Verifying raylib installation..."
	@echo "1. Checking for raylib.h header..."
	@if [ -f /usr/local/include/raylib.h ] || [ -f /usr/include/raylib.h ] || [ -f /opt/homebrew/include/raylib.h ]; then \
		echo "   ✓ raylib.h found"; \
	else \
		echo "   ✗ raylib.h not found"; \
		echo "   Please install raylib first: make install-raylib"; \
		exit 1; \
	fi
	@echo "2. Checking for libraylib..."
	@if [ -f /usr/local/lib/libraylib.a ] || [ -f /usr/lib/libraylib.a ] || [ -f /opt/homebrew/lib/libraylib.a ]; then \
		echo "   ✓ libraylib found"; \
	else \
		echo "   ✗ libraylib not found"; \
		echo "   Please install raylib first: make install-raylib"; \
		exit 1; \
	fi
	@echo "3. Checking pkg-config..."
	@if pkg-config --exists raylib 2>/dev/null; then \
		echo "   ✓ pkg-config raylib found"; \
		echo "   Current flags: $$(pkg-config --cflags --libs raylib)"; \
		echo "   Static flags: $$(pkg-config --cflags --libs --static raylib 2>/dev/null || echo 'not supported')"; \
	else \
		echo "   ⚠ pkg-config raylib not found (manual flags will be used)"; \
	fi
	@echo "4. Testing compilation..."
	@printf '#include "raylib.h"\nint main(){InitWindow(1,1,"test");CloseWindow();return 0;}' > test_raylib_temp.c
	@if $(CC) $(CFLAGS) $(RAYLIB_CFLAGS) test_raylib_temp.c -o test_raylib_temp $(LDFLAGS) $(RAYLIB_LIBS) 2>/dev/null; then \
		echo "   ✓ Test compilation successful"; \
		rm -f test_raylib_temp.c test_raylib_temp; \
	else \
		echo "   ✗ Test compilation failed"; \
		echo "   Try running: make fix-raylib-pkgconfig"; \
		rm -f test_raylib_temp.c test_raylib_temp; \
		exit 1; \
	fi
	@echo "✓ raylib installation verified successfully!"

# Install raylib (Linux/macOS)
install-raylib:
ifeq ($(PLATFORM),LINUX)
	@echo "Installing raylib on Linux..."
	@if command -v apt >/dev/null 2>&1; then \
		echo "Trying to install raylib via apt..."; \
		sudo apt update && sudo apt install -y libraylib-dev || \
		echo "Package not found, please install raylib manually from: https://github.com/raysan5/raylib"; \
	elif command -v pacman >/dev/null 2>&1; then \
		echo "Trying to install raylib via pacman..."; \
		sudo pacman -S raylib || \
		echo "Package not found, please install raylib manually from: https://github.com/raysan5/raylib"; \
	elif command -v dnf >/dev/null 2>&1; then \
		echo "Trying to install raylib via dnf..."; \
		sudo dnf install raylib-devel || \
		echo "Package not found, please install raylib manually from: https://github.com/raysan5/raylib"; \
	else \
		echo "No supported package manager found. Please install raylib manually from: https://github.com/raysan5/raylib"; \
	fi
endif
ifeq ($(PLATFORM),OSX)
	@echo "Installing raylib on macOS..."
	@if command -v brew >/dev/null 2>&1; then \
		echo "Installing raylib via Homebrew..."; \
		brew install raylib; \
	else \
		echo "Homebrew not found. Please install Homebrew first or install raylib manually from: https://github.com/raysan5/raylib"; \
	fi
endif

# Run the program
run: $(PROJECT_NAME)
ifeq ($(TARGET),WEB)
	@echo "Starting web server for $(PROJECT_NAME).html..."
	@if command -v python3 >/dev/null 2>&1; then \
		python3 -m http.server 8000; \
	elif command -v python >/dev/null 2>&1; then \
		python -m SimpleHTTPServer 8000; \
	else \
		echo "Python not found. Please open $(PROJECT_NAME).html in a web server."; \
	fi
else
	./$(PROJECT_NAME)$(EXT)
endif

# Debug build
debug: CFLAGS += -g -O0 -DDEBUG
debug: $(PROJECT_NAME)

# Release build
release: CFLAGS += -O2 -DNDEBUG
release: $(PROJECT_NAME)

# Help
help:
	@echo "Available targets:"
	@echo "  all       - Build for current platform (default)"
	@echo "  web       - Build for web (requires Emscripten)"
	@echo "  debug     - Build with debug information"
	@echo "  release   - Build optimized for release"
	@echo "  run       - Build and run the program"
	@echo "  clean     - Remove compiled files"
	@echo ""
	@echo "Raylib management:"
	@echo "  install-raylib        - Install raylib on Linux/macOS"
	@echo "  verify-raylib         - Verify raylib installation"
	@echo "  fix-raylib-pkgconfig  - Fix raylib pkg-config file"
	@echo ""
	@echo "Help:"
	@echo "  help      - Show this help message"
	@echo ""
	@echo "Environment variables:"
	@echo "  CC        - Compiler to use (default: gcc)"
	@echo "  RAYLIB_PATH - Path to raylib installation (Windows)"
	@echo ""

.PHONY: all info web install-raylib run clean debug release help

# Clean compiled files
clean:
	rm -f $(PROJECT_NAME)$(EXT) $(PROJECT_NAME).js $(PROJECT_NAME).wasm $(PROJECT_NAME).data