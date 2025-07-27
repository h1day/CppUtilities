# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview
This is a Windows-centric C++20 CMake project using MSVC toolchain and Ninja build system. Currently a minimal utility framework with "Hello CMake" implementation, ready for expansion.

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

# VS Code tasks (Ctrl+Shift+P → Tasks: Run Task)
- "Build Debug" (default)
- "Build Release" 
- "Configure Debug"
- "Clean"
```

## Architecture Notes
- **Target**: Single executable `CppUtilities.exe`
- **Standard**: C++20 with MSVC hot reload support enabled
- **Structure**: Simple main.cpp + header, standard library only
- **Build Output**: `out/build/x64-debug/` or `out/build/x64-release/`
- **CMake Version**: Requires 3.20+ (specified in CMakeLists.txt line 4)

## Development Workflow
1. Environment setup is critical - always use Native Tools Command Prompt
2. CMake presets (x64-debug/x64-release) are configured for consistent builds
3. VS Code debugging configured with cppvsdbg for Windows
4. Japanese documentation in README.md indicates possible i18n considerations

## Key Files
- `CMakePresets.json`: Defines x64-debug/release configurations with Ninja generator
- `CppUtilities.h`: Main header with `#pragma once`, includes `<iostream>`
- `.vscode/`: Complete VS Code integration (CMake Tools, debug config, tasks)

## Testing Status
No testing framework currently implemented. CMakeLists.txt has TODO comment for adding tests (line 21).

## Code Modification Guidelines
**IMPORTANT: Always verify technical claims before making changes:**
- Use WebFetch to check official documentation for compiler flags, build settings, etc.
- Don't assume "common knowledge" - verify Microsoft/CMake/C++ documentation
- When removing or adding compiler flags, always check the official reference first
- For MSVC flags: https://learn.microsoft.com/en-us/cpp/build/reference/
- For CMake: https://cmake.org/documentation/

**Research-first approach:**
1. Before suggesting changes, research the current behavior
2. Verify default values and recommended practices
3. Check for platform-specific differences
4. Only then propose modifications with evidence
