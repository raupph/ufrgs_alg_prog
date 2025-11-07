# Exemplos de Uso Multiplataforma

## Linux/Ubuntu
```bash
# Instalação automática
./setup.sh

# Compilação básica
make
make run

# Com diferentes compiladores
CC=gcc make
CC=clang make

# Builds especiais
make debug      # Com símbolos de debug
make release    # Otimizado
```

## macOS
```bash
# Instalação com Homebrew
brew install raylib

# Compilação (frameworks automáticos)
make
make run

# Force usar clang
CC=clang make
```

## Windows (MSYS2)
```bash
# No terminal MSYS2 MinGW 64-bit
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-raylib

# Compilação
make
make run
```

## Web (Emscripten)
```bash
# Configurar Emscripten
source /path/to/emsdk/emsdk_env.sh

# Compilar para web
make web

# Executar (inicia servidor HTTP)
make run
# Acesse: http://localhost:8000/ex1_executavel.html
```

## Variáveis de Ambiente
```bash
# Usar compilador específico
CC=clang make

# Path customizado do raylib (Windows)
RAYLIB_PATH="C:/raylib/raylib" make

# Forçar target web
TARGET=WEB make

# Build verbose
V=1 make
```

## Integração com IDEs

### VS Code
Crie `.vscode/tasks.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "make",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        },
        {
            "label": "run",
            "type": "shell",
            "command": "make",
            "args": ["run"],
            "dependsOn": "build"
        }
    ]
}
```

### CLion/outros IDEs CMake
O projeto pode ser adaptado para CMake se necessário.