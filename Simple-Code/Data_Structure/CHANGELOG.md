# Changelog

All notable changes to **Data Structure Visualizer** will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- **Complete Qt5 Native Styling System** with QPalette integration for perfect theme consistency
- **Professional Desktop UX overhaul**:
  - Standardized 16px window margins (from inconsistent spacing)
  - Compact 12px component spacing for better space utilization
  - Professional 1000x700 minimum window size with 1200x800 default
  - Perfect button alignment with consistent 35px height
- **Advanced Operations Toolbar** with Clear, Export, Import, About functions
- **Realistic 3D-Style Visualizations**:
  - **Card Stack** with shadows, depth effects, and wooden base platform
  - **Linked Nodes** with arrow connections for linked list
  - Enhanced tree structures with proper branching visualization
  - Professional empty states with clear messaging
- **Comprehensive Keyboard Shortcuts**:
  - `Ctrl+Q`: Quit application
  - `Ctrl+Tab`: Next data structure
  - `Ctrl+Shift+Tab`: Previous data structure
  - `Ctrl+T`: Cycle themes
  - `Ctrl+C`: Clear data structure
  - `Ctrl+E`: Export data
  - `Ctrl+I`: Import data
  - `Ctrl+A`: About dialog
- **Enhanced Status Bar** with data structure info, memory tracking, and operation counts
- **Data Persistence** with export/import functionality for Linked List
- **User Experience Improvements**:
  - Helpful tooltips on all interactive elements
  - Smooth theme transitions
  - Theme-aware toolbar visibility fixes
  - Dynamic theme updating without application restart
- **Complete Data Structure Implementations**:
  - **Stack**: Visual card stack with realistic 3D effects
  - Linked List: Professional node visualization with connections
  - Heap: Min/Max heap with tree structure
  - Binary Search Tree: Complete BST with traversals
  - Circular Queue: Ring-style visualization
  - Queue via Stacks: Algorithm demonstration
  - Trie: Prefix tree with character connections

### Changed
- **Complete Qt5 Integration Overhaul**: Replaced CSS overrides with native QPalette system
- **Professional Desktop Layout**: Eliminated excessive spacing, standardized margins/spacing to desktop standards
- **ToolBar Visibility**: Fixed toolbar not showing in themes, now visible and theme-aware
- **Status Bar Layout**: Compact segmented layout with theme-aware styling
- **Theme System**: Enhanced with Qt5 native palette integration for perfect consistency
- **Build System**: Optimized with Qt5-specific enhancements

### Fixed
- **Toolbar Visibility Issue**: Added explicit styling, size policies, and Qt::singleShot() debugging
- **Button Alignment Problems**: Resolved inconsistent sizing and spacing issues
- **Qt5 Theme Integration**: Eliminated QPalette conflicts for seamless theme switching
- **Professional Spacing**: Standardized desktop application spacing standards
- **Window Sizing**: Proper minimum/maximum sizes with professional defaults

### Technical
- **Qt5 QPalette Integration**: Complete theme system using Qt's native color management
- **Professional Desktop Standards**: 16px margins, 12px spacing, 40px button heights
- **Toolbar Implementation**: Qt QToolBar with QAction, theme-aware styling
- **Visualization Rendering**: Enhanced QGraphicsScene with realistic 3D effects
- **Memory Management**: Proper Qt object hierarchy and resource cleanup
- **Cross-Platform Compatibility**: Qt5 framework ensures consistent behavior

## [1.0.0] - 2025-01-20

### Added
- **Initial Release** of Data Structure Visualizer
- **Modern Theme System** with 4 themes:
  - Modern Blue (indigo-based)
  - Modern Green (nature-inspired)
  - Light theme (clean)
  - Dark theme (modern)
- **Real-time Visualization** for all data structures
- **Interactive GUI** with Qt5 framework

### Features
- **Singly Linked List** - Insert, delete, search operations
- **Stack** - Push, pop, peek operations (LIFO)
- **Heap** - Binary heap with min/max configurations
- **Binary Search Tree** - Insert, traversal operations
- **Circular Queue** - Fixed-size queue implementation
- **Queue via Stacks** - Algorithm implementation
- **Trie** - Prefix tree for strings

### Development Features
- Cross-platform support (Linux/MacOS/Windows)
- Professional Qt5 GUI application
- CMake build system
- C++17 standard compliance
- Real-time graphics visualization
- Responsive design

### Technical Details
- Built with Qt5 (tested with 5.15)
- C++17 features throughout
- CMake build configuration
- Modular architecture design
- Event-driven GUI updates
- Custom styling system

---

## Types of changes
- `Added` for new features
- `Changed` for changes in existing functionality
- `Deprecated` for soon-to-be removed features
- `Removed` for now removed features
- `Fixed` for any bug fixes
- `Security` in case of vulnerabilities

## Version Format
This project uses [Semantic Versioning](https://semver.org/):
- **MAJOR.MINOR.PATCH** (e.g., 1.0.0)
- **MAJOR**: Breaking changes
- **MINOR**: New features (backward compatible)
- **PATCH**: Bug fixes (backward compatible)

---

*Changelog format follows [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)*
*Semantic Versioning follows [SemVer](https://semver.org/)*
