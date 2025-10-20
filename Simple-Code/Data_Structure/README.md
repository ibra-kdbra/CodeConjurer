# Data Structure Visualizer

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/yourusername/DataStructureVisualizer/blob/main/LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-17-orange.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![Qt](https://img.shields.io/badge/Qt-5.15-green.svg)](https://qt.io)
[![CMake](https://img.shields.io/badge/CMake-3.16-red.svg)](https://cmake.org)
[![Desktop](https://img.shields.io/badge/Desktop-Application-purple.svg)]()

A **professional desktop application** for visualizing fundamental data structures and algorithms with **native Qt5 integration**, **realistic 3D visualizations**, and **themeable modern GUI interface**.

## 🎯 Features

### **Data Structures with Realistic Visualizations**
- **Singly Linked List** - Professional node visualization with arrow connections
- **Stack** - Real 3D card stack with shadows, depth effects, and wooden base
- **Heap** - Interactive tree visualization with Min/Max heap configurations
- **Binary Search Tree** - Complete BST with traversals (preorder, inorder, postorder)
- **Circular Queue** - Ring-style circular visualization with FRONT/REAR markers
- **Queue via Stacks** - Algorithm demonstration showing two-stack implementation
- **Trie** - Prefix tree network with character connections and word endings

### **Professional Desktop GUI Features**
- **Qt5 Native Styling** - Complete QPalette integration for perfect theme consistency
- **4 Beautiful Themes**: Modern Blue, Modern Green, Light, and Dark
- **Professional Toolbar** - Clear, Export, Import, and About functions
- **Enhanced Status Bar** - Data structure info, memory usage, operation counters
- **Real-time Visualization** - Interactive graphics with realistic 3D effects
- **Responsive Layout** - Proper window sizing (1200x800 default, 1000x700 minimum)
- **Smooth Theme Transitions** - Instant theme switching without restart
- **Helpful Tooltips** - Context-aware guidance for all interactive elements

### **Advanced User Experience**
- **Comprehensive Keyboard Shortcuts** - 8+ shortcuts for power users
- **Data Export/Import** - Save/load data structures to/from files
- **Professional Spacing Standards** - 16px margins, 12px spacing, 40px toolbar
- **Theme-Aware Controls** - Perfect alignment and consistent heights
- **Cross-Platform Compatibility** - Runs on Linux, macOS, and Windows

## 📋 Requirements

- C++17 compatible compiler
- Qt5 (Widgets, Core, Gui components)
- CMake 3.16 or higher
- Linux/MacOS/Windows support

### Dependencies
- Qt5 5.12+ (tested with 5.15)
- CMake 3.16+
- C++17 compiler (GCC 7+, Clang 5+, MSVC 2019+)

## 🛠️ Build Instructions

### Quick Start (Linux/MacOS)

```bash
cd Data_Structure

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
make

# Run application
./DataStructureVisualizer
```

### Cross-Platform Build

```bash
# Configure project
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build --parallel

# Run tests (if enabled)
cmake --build build --target test

# Install
cmake --build build --target install
```

if you are on linux, run this command:
```bash
./scripts/build.sh
```

## 🏗️ Project Structure

```
DataStructureVisualizer/
├── include/           # Public header files
│   ├── ds/           # Data structure headers
│   ├── gui/          # GUI component headers
│   └── utilities/    # Utility headers
├── resources/        # Assets and resources
├── scripts/          # Build and deployment scripts
├── src/              # Source implementation
│   ├── core/         # Data structure algorithms
│   ├── gui/          # GUI implementations
│   └── visualization/ # Visualization components
├── CMakeLists.txt    # Main build configuration
├── CHANGELOG.md      # Version history
├── LICENSE           # Project license
├── README.md         # This file
└── .gitignore        # Git ignore rules
```


## 📚 Usage

1. **Select Data Structure**: Choose from the dropdown menu
2. **Choose Theme**: Switch between 4 available themes
3. **Perform Operations**: Use buttons to insert, remove, search, etc.
4. **View Results**: Watch real-time visualizations and operations

## 🛠️ Toolbar Operations

The application includes a professional toolbar for quick operations:

- **🔄 Clear**: Clear all data from the current data structure (`Ctrl+C`)
- **📤 Export**: Export current data structure to a text file (`Ctrl+E`)
- **📥 Import**: Import data from a text file to current data structure (`Ctrl+I`)
- **❓ About**: Show application information and version (`Ctrl+A`)

*Export and Import are currently supported for Linked List data structure*

## ⌨️ Keyboard Shortcuts

### Application Controls
- **`Ctrl+Q`** - Quit application
- **`Ctrl+T`** - Cycle through themes (Modern Blue → Modern Green → Light → Dark)

### Data Structure Navigation
- **`Ctrl+Tab`** - Switch to next data structure
- **`Ctrl+Shift+Tab`** - Switch to previous data structure

### Data Structure Operations
- **`Ctrl+C`** - Clear current data structure
- **`Ctrl+E`** - Export current data structure
- **`Ctrl+I`** - Import data to current data structure
- **`Ctrl+A`** - Show About dialog

## 🎯 Data Structure Operations

### Singly Linked List
- **Push**: Add element to head (O(1)) → ⭐ **Export/Import supported**
- **Insert After**: Add element after specified value (O(n))
- **Pop**: Remove head element (O(1))
- **Export**: Save list to text file with proper formatting
- **Import**: Load list from text file with validation

### Stack (3D Card Visualization)
- **Push**: Add element to top with realistic card animation (O(1))
- **Pop**: Remove top element with stacking effects (O(1))
- **Peek**: View top element without removing it (O(1))
- **Clear**: Remove all cards from the stack
- *Cards are rendered with shadows, depth, and wooden base platform*

### Heap (Tree Visualization)
- **Insert**: Add element and maintain heap property (O(log n))
- **Extract**: Remove root element with tree restructuring (O(log n))
- **Min/Max Toggle**: Switch between minimum and maximum heap
- *Interactive tree visualization with proper branching*

### Binary Search Tree (BST)
- **Insert**: Add element maintaining BST property (O(log n))
- **In-Order Traversal**: Left → Root → Right (O(n))
- **Pre-Order Traversal**: Root → Left → Right (O(n))
- **Post-Order Traversal**: Left → Right → Root (O(n))
- *Complete tree visualization with label nodes*

### Circular Queue (Ring Visualization)
- **Enqueue**: Add element to rear of circular buffer (O(1))
- **Dequeue**: Remove element from front of buffer (O(1))
- **Front**: View front element without removing (O(1))
- *Ring-style circular visualization with FRONT/REAR markers*

### Queue via Stacks (Algorithm Demo)
- **Enqueue**: Add element using two-stack algorithm (amortized O(1))
- **Dequeue**: Remove element with stack reversal (amortized O(1))
- **Front**: Show front element (O(1))
- *Demonstrates the classic algorithmic implementation*

### Trie (Prefix Tree)
- **Insert**: Add word to prefix tree structure (O(m))
- **Search**: Find exact word match (O(m))
- **Starts With**: Check if any words start with prefix (O(m))
- *Word network visualization with character connections*

### Development Guidelines
- Follow C++17 standards
- Use Qt5 QWidget framework
- Maintain separation of concerns (core/GUI/visualization)
- Add tests for new features
- Update documentation

## 🗺️ Roadmap

### Future Enhancements
- [ ] **New Data Structures**: AVL Trees, Red-Black Trees, Hash Tables
- [ ] **Advanced Visualizations**: Animation controls, step-by-step execution
- [ ] **Algorithm Analysis**: Time/space complexity comparisons
- [ ] **Export Features**: Save visualizations as images/PDF
- [ ] **Cross-platform**: Enhanced platform support
- [ ] **Web Version**: Browser-based implementation

*See [CHANGELOG.md](CHANGELOG.md) for current version details*
