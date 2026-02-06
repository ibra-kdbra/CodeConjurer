# Getting Started

This guide will help you get up and running with the CodeConjurer projects.

## 📋 Prerequisites

Before working with the projects in this repository, ensure you have the following installed:

### Essential Tools
- **Git** - For cloning the repository
- **C++ Compiler** - GCC 9+, Clang 10+, or MSVC 2019+
- **CMake** (3.16+) - Most projects use CMake for building
- **Make** or **Ninja** - Build system

### Optional Dependencies (Project-Specific)

| Library | Projects Using It |
|---------|-------------------|
| [SFML](https://www.sfml-dev.org/) | Snake, Hangman, SFML_Multithread_verlet |
| [SDL2](https://www.libsdl.org/) | POng, simplesdl2_game_template |
| [OpenGL](https://www.opengl.org/) | Chess_3D, OpenGL_examples, Trigonometric-Functions, volumetric-clouds |
| [GLFW](https://www.glfw.org/) | Chess_3D, volumetric-clouds |
| [GLM](https://github.com/g-truc/glm) | Chess_3D, OpenGL_examples |
| [Qt5](https://www.qt.io/) | WordProc |
| [ncurses](https://invisible-island.net/ncurses/) | SystemMonitor, Terminal_File_Manager, Matrix_ScreenSaver |

## 🚀 Quick Start

### 1. Clone the Repository

```bash
git clone https://github.com/ibra-kdbra/CodeConjurer.git
cd CodeConjurer
```

### 2. Choose a Project

Navigate to the project directory you want to explore:

```bash
cd <project-name>
# Example: cd Chess_3D
```

### 3. Read the Project README

Each project has its own README with specific build and run instructions:

```bash
cat README.md
# or open README.md in your editor
```

### 4. Build the Project

Most projects follow one of these patterns:

#### CMake Projects

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

#### Make Projects

```bash
make
```

#### Direct Compilation

```bash
g++ -std=c++17 main.cpp -o main
```

## 🔧 Common Build Patterns

### CMake with Dependencies

For projects requiring external libraries:

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

### Installing Dependencies

#### Ubuntu/Debian

```bash
# Essential build tools
sudo apt update
sudo apt install build-essential cmake git

# Graphics libraries
sudo apt install libsfml-dev libsdl2-dev libglfw3-dev libglm-dev

# Qt5
sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools

# ncurses
sudo apt install libncurses5-dev libncursesw5-dev
```

#### macOS (Homebrew)

```bash
# Essential tools
brew install cmake

# Graphics libraries
brew install sfml sdl2 glfw glm

# Qt5
brew install qt@5

# ncurses (usually pre-installed)
brew install ncurses
```

#### Windows (vcpkg)

```powershell
# Install vcpkg if not already installed
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat

# Install libraries
.\vcpkg install sfml:x64-windows
.\vcpkg install sdl2:x64-windows
.\vcpkg install glfw3:x64-windows
.\vcpkg install glm:x64-windows
```

## 📁 Project Structure

Each project typically follows this structure:

```
project-name/
├── README.md           # Project-specific documentation
├── CMakeLists.txt      # CMake build configuration (if using CMake)
├── Makefile            # Make build configuration (if using Make)
├── src/                # Source files
├── include/            # Header files
├── assets/             # Resources (images, sounds, etc.)
├── screenshots/        # Preview images
└── tests/              # Test files (if available)
```

## 🐛 Troubleshooting

### Common Issues

#### "CMake not found"
```bash
# Install CMake
# Ubuntu: sudo apt install cmake
# macOS: brew install cmake
# Windows: Download from cmake.org
```

#### "Library not found"
Make sure you've installed the required dependencies for the specific project. Check the project's README for requirements.

#### "C++17/20 features not supported"
Update your compiler to a newer version:
```bash
# Check your compiler version
g++ --version
clang++ --version

# Ubuntu: Install newer GCC
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install g++-11
```

#### "Permission denied" when running
```bash
chmod +x ./executable_name
./executable_name
```

## 💡 Tips

1. **Start Simple**: Begin with simpler projects like `Collatz` or `Hangman` before tackling complex ones like `MarbleMarcher`.

2. **Read the Code**: Each project is an opportunity to learn. Take time to understand the implementation.

3. **Check Issues**: If you encounter problems, check the GitHub Issues page for known problems and solutions.

4. **Experiment**: Modify the code and see what happens! This is a playground after all.

## 📚 Next Steps

- [View all projects](Project-Overview)
- [Browse by category](Project-Categories)
- [Contribute to the project](Contributing)
