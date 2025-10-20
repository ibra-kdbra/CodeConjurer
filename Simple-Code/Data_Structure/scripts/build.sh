#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

BUILD_TYPE="${1:-release}"
BUILD_DIR="$PROJECT_ROOT/build"

echo "🔨 Building Data Structure Visualizer ($BUILD_TYPE)"

case "$BUILD_TYPE" in
    "debug")
        CMAKE_ARGS="-DCMAKE_BUILD_TYPE=Debug"
        ;;
    "release")
        CMAKE_ARGS="-DCMAKE_BUILD_TYPE=Release"
        ;;
    "clean")
        echo "🧹 Cleaning build directory..."
        rm -rf "$BUILD_DIR"
        echo "✅ Cleaned successfully"
        exit 0
        ;;
    *)
        echo "❌ Invalid build type. Use: debug|release|clean"
        exit 1
        ;;
esac

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

# Change to build directory
cd "$BUILD_DIR"

# Configure project
echo "⚙️  Configuring project..."
cmake "$PROJECT_ROOT" $CMAKE_ARGS

# Build project
echo "🔨 Building project..."
make -j$(nproc)

echo "✅ Build completed successfully!"
echo "📂 Executable: $BUILD_DIR/DataStructureVisualizer"

# Run if requested
if [ "$2" = "run" ]; then
    echo "🚀 Running application..."
    ./DataStructureVisualizer
fi
