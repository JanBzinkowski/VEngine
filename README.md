# VEngine

A C++ project using CMake build system.

## Requirements

- CMake 3.20 or higher
- C++ compiler with C++23 support
- JetBrains Rider

## Building

Configure and build from the repository root:

```sh
cmake -S . -B build
cmake --build build
```

The `VEngine` executable is the application target; `VEngineLib` contains the engine code and can be linked by other CMake targets. Rider can open the project directory and configure the targets directly from `CMakeLists.txt`.

## Project Structure

- `src/` - Source files
- `include/` - Public headers
- `CMakeLists.txt` - CMake configuration
