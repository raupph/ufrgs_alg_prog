# Raylib Cross-Platform Project

Este projeto fornece uma configuração multiplataforma para desenvolvimento com raylib em C, funcionando automaticamente no **Linux**, **macOS**, **Windows** e **Web** (Emscripten).

## 🚀 Instalação Rápida

### Opção 1: Script Automático (Recomendado)
```bash
# Clone ou baixe este projeto
# Então execute:
./setup.sh
```

O script irá:
- Detectar automaticamente seu sistema operacional
- Instalar raylib e dependências
- Configurar tudo automaticamente
- Testar a instalação

### Opção 2: Instalação Manual

#### Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install build-essential git cmake
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev

# Instalar raylib (se disponível no repositório)
sudo apt install libraylib-dev

# OU build from source se não estiver disponível
git clone https://github.com/raysan5/raylib.git
cd raylib && mkdir build && cd build
cmake .. && make -j4 && sudo make install
sudo ldconfig
```

#### Linux (Arch/Manjaro)
```bash
sudo pacman -S base-devel raylib
```

#### macOS
```bash
# Instalar Homebrew se necessário
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Instalar raylib
brew install raylib
```

#### Windows (MSYS2)
```bash
# No terminal MSYS2
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-raylib
```

## 🛠️ Como Usar

### Compilação Básica
```bash
make          # Compila para a plataforma atual
make run      # Compila e executa
make clean    # Limpa arquivos compilados
```

### Builds Especiais
```bash
make debug    # Compila com informações de debug
make release  # Compila otimizado para release
make web      # Compila para web (requer Emscripten)
```

### Outras Opções
```bash
make help               # Mostra todos os comandos disponíveis
make install-raylib     # Instala raylib automaticamente
make info              # Mostra informações do build
```

## 🌐 Compilação para Web

Para compilar para web, primeiro instale o Emscripten:

```bash
# Instalar Emscripten
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh

# Compilar projeto para web
make web

# Executar no navegador
make run  # (com TARGET=WEB, iniciará servidor HTTP)
```

## 📁 Estrutura do Projeto

```
projeto/
├── Makefile          # Makefile multiplataforma
├── setup.sh          # Script de instalação automática
├── pratica1.c        # Seu código fonte
├── README.md         # Esta documentação
└── ex1_executavel    # Executável (após compilar)
```

## 🎯 Recursos do Makefile

### Detecção Automática de Plataforma
- **Linux**: Usa pkg-config ou fallback manual
- **macOS**: Suporte a Homebrew e frameworks Apple
- **Windows**: Suporte a MinGW/MSYS2
- **Web**: Compilação com Emscripten

### Paths Automáticos
O Makefile detecta automaticamente raylib em:
- `/usr/local/` (instalação padrão)
- `/usr/` (instalação do sistema)
- `/opt/homebrew/` (Homebrew no Apple Silicon)
- `C:/raylib/` (Windows padrão)

### Variáveis de Ambiente
```bash
CC=clang make              # Usar clang ao invés de gcc
RAYLIB_PATH=/path make     # Especificar path do raylib
TARGET=WEB make           # Forçar compilação web
```

## ❓ Por que Tantas Flags?

**Isso é normal e esperado!** Raylib é uma biblioteca **estática** (`.a`), não dinâmica (`.so`). 

### Diferença:
- **Biblioteca Dinâmica**: Resolve dependências automaticamente em runtime
- **Biblioteca Estática**: Você deve especificar todas as dependências manualmente

### Por que cada flag é necessária:
- `-lraylib` - A biblioteca raylib principal  
- `-lGL` - OpenGL para renderização gráfica
- `-lm` - Funções matemáticas (sin, cos, sqrt, etc.)
- `-lpthread` - Multi-threading
- `-ldl` - Carregamento dinâmico de drivers
- `-lrt` - Timing preciso
- `-lX11` - Sistema de janelas do Linux

### Solução:
**Use o Makefile!** Ele resolve tudo automaticamente:
```bash
make        # Compila com todas as flags corretas
make run    # Compila e executa
```

## 🔧 Personalização

### Modificar o projeto
1. Edite `pratica1.c` com seu código
2. Para múltiplos arquivos, modifique `SOURCE_FILE` no Makefile
3. Para mudar o nome do executável, modifique `PROJECT_NAME`

### Adicionar bibliotecas extras
```makefile
# No Makefile, adicione na seção da sua plataforma:
RAYLIB_LIBS += -lminha_biblioteca
```

## 🐛 Solução de Problemas

### "raylib.h: No such file or directory"
```bash
# Instale raylib
./setup.sh
# OU
make install-raylib
```

### "undefined reference to math functions"
O Makefile já inclui `-lm`, mas se necessário:
```bash
# Compile manualmente com:
gcc pratica1.c -o programa -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

### Windows: "raylib not found"
1. Instale MSYS2: https://www.msys2.org/
2. Use o terminal MSYS2 MinGW 64-bit
3. Execute `./setup.sh`

### macOS: "framework not found"
```bash
# Instale Xcode command line tools
xcode-select --install
# Instale Homebrew e raylib
brew install raylib
```

## 📚 Exemplos de Uso

### Compilação Simples
```bash
make && ./ex1_executavel
```

### Debug
```bash
make debug
gdb ./ex1_executavel
```

### Cross-compilation para Web
```bash
source /path/to/emsdk/emsdk_env.sh
make web
python3 -m http.server 8000  # Abra localhost:8000
```

## 🤝 Contribuição

1. Faça um fork do projeto
2. Crie uma branch para sua feature
3. Commit suas mudanças
4. Abra um Pull Request

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para detalhes.

## 🔗 Links Úteis

- [Raylib Official Website](https://www.raylib.com/)
- [Raylib GitHub](https://github.com/raysan5/raylib)
- [Raylib Examples](https://www.raylib.com/examples.html)
- [Raylib Cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)

---

**Nota**: Este setup foi testado em Ubuntu 24.04, macOS Big Sur+, Windows 10+ com MSYS2, e navegadores modernos com WebAssembly.