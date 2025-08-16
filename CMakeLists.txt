# CMakeList.txt : CppUtilities の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.20)

# サポートされている場合は、MSVC コンパイラのホット リロードを有効にします。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CppUtilities")

# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (CppUtilities "CppUtilities.cpp" "CppUtilities.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CppUtilities PROPERTY CXX_STANDARD 20)
endif()

# CppUTest フレームワークの設定
include(FetchContent)

# CppUTest の設定オプション (FetchContent_Declare の前に設定)
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
set(MEMORY_LEAK_DETECTION OFF CACHE BOOL "Switch off memory leak detection")
set(CPPUTEST_FLAGS OFF CACHE BOOL "Switch off CppUTest flags to avoid -Werror")
set(C++11 ON CACHE BOOL "Enable C++11 support")

FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master  # より新しいバージョンを使用
)

FetchContent_MakeAvailable(CppUTest)

# CppUTest のコンパイラフラグを調整 (警告をエラーとして扱わない)
if(TARGET CppUTest)
    target_compile_options(CppUTest PRIVATE
        $<$<CXX_COMPILER_ID:Clang>:-Wno-error>
        $<$<CXX_COMPILER_ID:MSVC>:/WX->
    )
endif()

if(TARGET CppUTestExt)
    target_compile_options(CppUTestExt PRIVATE
        $<$<CXX_COMPILER_ID:Clang>:-Wno-error>
        $<$<CXX_COMPILER_ID:MSVC>:/WX->
    )
endif()

# CTest を有効化
enable_testing()

# テスト用のサブディレクトリを追加
add_subdirectory(tests)
