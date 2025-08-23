# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview
This is a Windows-centric C++20 CMake project using MSVC toolchain and Ninja build system. It's a C++ utility library project with CppUTest framework integration for comprehensive testing capabilities.

## Critical Environment Setup
**VS Code must be launched from x64 Native Tools Command Prompt for VS 2022:**
```cmd
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
code "C:\work\CppUtilities"
```
This ensures MSVC compiler (cl.exe) is in PATH for Ninja builds.

## Build Commands
```bash
# Configure and build using CMake presets
cmake --preset x64-debug
cmake --build out/build/x64-debug --config Debug

cmake --preset x64-release  
cmake --build out/build/x64-release --config Release

# VS Code tasks (Ctrl+Shift+P → Tasks: Run Task)
- "Build Debug" (default, depends on Configure Debug)
- "Build Release" (depends on Configure Release)
- "Build Tests" (builds test executable)
- "Configure Debug/Release"
- "Clean Debug/Release"
```

## Test Commands
```bash
# Build and run all tests
cmake --build out/build/x64-debug --config Debug
out/build/x64-debug/tests/CppUtilities_tests.exe

# CTest integration 
cd out/build/x64-debug
ctest --verbose

# CppUTest specific commands
CppUtilities_tests.exe -ll                              # List all tests
CppUtilities_tests.exe -g CppUtilitiesBasicTests        # Run test group
CppUtilities_tests.exe -g CppUtilitiesBasicTests -n BasicMathTest  # Run specific test
CppUtilities_tests.exe -v                               # Verbose output
```

## Architecture and Structure

### Key Targets
- **Main executable**: `CppUtilities.exe` - Minimal "Hello CMake" implementation
- **Test executable**: `CppUtilities_tests.exe` - CppUTest-based test suite

### Build Architecture
- **Standard**: C++20 with MSVC hot reload support
- **Build system**: CMake 3.20+ with Ninja generator
- **Output directories**:
  - Debug: `out/build/x64-debug/`
  - Release: `out/build/x64-release/`
  - Tests: `out/build/x64-debug/tests/`

### CMake Integration
- **CppUTest Framework**: Integrated via FetchContent from master branch
- **CTest Integration**: Automatic test registration and discovery
- **Presets**: x64-debug and x64-release with optimized MSVC flags
- **Hot Reload**: Enabled with EditAndContinue debug info format

### Test Framework Architecture
- **Framework**: CppUTest with full VS Code integration
- **Test Structure**: 
  - `tests/test_main.cpp` - CppUTest runner
  - `tests/test_utilities.cpp` - Test cases implementation
  - `tests/CMakeLists.txt` - Test-specific CMake configuration
- **Current Tests**: CppUtilitiesBasicTests group with BasicMathTest, StringTest, OutputTest
- **VS Code Integration**: CppUTest Test Adapter for Test Explorer functionality

## Development Workflow

### VS Code Integration
1. **Required Extension**: CppUTest Test Adapter for full test functionality
2. **Test Explorer**: Automatic test discovery and hierarchical display
3. **Debug Support**: F5 debugging for both main application and individual tests
4. **IntelliSense**: Powered by CMAKE_EXPORT_COMPILE_COMMANDS=ON

### Code Quality Tools
- `.clang-format` - Code formatting configuration
- `.clang-tidy` - Static analysis configuration  
- `Folder.DotSettings` - ReSharper code inspection settings

## Key Files and Configuration

### Core Files
- `CMakeLists.txt`: Main build configuration with CppUTest integration
- `CMakePresets.json`: x64-debug/release presets with Ninja generator
- `CppUtilities.h/.cpp`: Main source files with simple utility framework

### VS Code Configuration
- `.vscode/settings.json`: CMake Tools integration with preset auto-selection
- `.vscode/tasks.json`: Build tasks with dependency chains and MSVC problem matcher
- `.vscode/launch.json`: Debug configurations for main app and tests

### Test Configuration
- `tests/CMakeLists.txt`: Advanced test configuration with auto-discovery
- Test discovery via `-ll` option for VS Code Test Adapter integration
- CTest registration for both individual and group test execution

## Code Modification Guidelines

### Research-First Approach
**IMPORTANT: Always verify technical claims before making changes:**
- Use WebFetch to check official documentation for compiler flags, build settings
- For MSVC flags: https://learn.microsoft.com/en-us/cpp/build/reference/
- For CMake: https://cmake.org/documentation/  
- For CppUTest: https://cpputest.github.io/

### Adding New Tests
1. Add test cases to `tests/test_utilities.cpp` using CppUTest TEST_GROUP/TEST macros
2. Tests automatically appear in VS Code Test Explorer after build
3. Follow existing pattern: CppUtilitiesBasicTests group structure

### Build System Modifications
1. Verify CMake version requirements (currently 3.20+)
2. Check MSVC hot reload policy settings before changes
3. Test both Debug and Release configurations
4. Ensure CppUTest integration remains functional

## Important Constraints
- Visual Studio 2022 environment required
- Windows-specific build configuration (MSVC toolchain)  
- Japanese documentation in README.md indicates i18n considerations
- CppUTest integration uses FetchContent - network access required for clean builds