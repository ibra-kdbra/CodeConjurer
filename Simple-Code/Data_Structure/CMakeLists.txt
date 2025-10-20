cmake_minimum_required(VERSION 3.16)
project(DataStructureVisualizer
    VERSION 1.0.0
    DESCRIPTION "Interactive Data Structure Visualizer with Modern GUI"
    LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Qt features
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

# Include directories for all modules
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ds
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gui
    ${CMAKE_CURRENT_SOURCE_DIR}/include/utilities
)

# Core data structures module
set(CORE_SOURCES
    src/core/BST.cpp
    src/core/CircularQueue.cpp
    src/core/Heap.cpp
    src/core/SinglyLinkedList.cpp
    src/core/Stack.cpp
)

set(CORE_HEADERS
    include/ds/BST.h
    include/ds/CircularQueue.h
    include/ds/Heap.h
    include/ds/SinglyLinkedList.h
    include/ds/Stack.h
)

# GUI module
set(GUI_SOURCES
    src/gui/MainWindow.cpp
    src/gui/StyleManager.cpp
)

set(GUI_HEADERS
    include/gui/MainWindow.h
    include/gui/StyleManager.h
)

# Visualization module
set(VISUALIZATION_SOURCES
    src/visualization/VisualBST.cpp
    src/visualization/VisualCircularQueue.cpp
    src/visualization/VisualHeap.cpp
    src/visualization/VisualLinkedList.cpp
    src/visualization/VisualQueueViaStacks.cpp
    src/visualization/VisualStack.cpp
    src/visualization/VisualTrie.cpp
)

set(VISUALIZATION_HEADERS
    include/gui/VisualBST.h
    include/gui/VisualCircularQueue.h
    include/gui/VisualHeap.h
    include/gui/VisualLinkedList.h
    include/gui/VisualQueueViaStacks.h
    include/gui/VisualStack.h
    include/gui/VisualTrie.h
)

# Main application
set(MAIN_SOURCES
    src/main.cpp
)

# Combine all sources and headers
set(ALL_SOURCES
    ${MAIN_SOURCES}
    ${CORE_SOURCES}
    ${GUI_SOURCES}
    ${VISUALIZATION_SOURCES}
)

set(ALL_HEADERS
    ${CORE_HEADERS}
    ${GUI_HEADERS}
    ${VISUALIZATION_HEADERS}
)

# Create resource files (for future icons, etc.)
qt5_add_resources(RESOURCES resources/resources.qrc)

# Build the main executable
add_executable(${PROJECT_NAME}
    ${ALL_SOURCES}
    ${ALL_HEADERS}
    ${RESOURCES}
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)

# Set target properties
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_BINARY_DIR}  # For generated Qt files
)

# Set compile features
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Enable testing if needed
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Installation rules
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
