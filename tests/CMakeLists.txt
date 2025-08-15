# テスト用の CMakeLists.txt

# テストファイルを収集
file(GLOB TEST_SOURCES "*.cpp")

# テスト実行可能ファイルを作成
add_executable(CppUtilities_tests ${TEST_SOURCES})

# CppUTest ライブラリをリンク
target_link_libraries(CppUtilities_tests 
    PRIVATE
    CppUTest
    CppUTestExt
)

# テストの実行可能ファイルを適切な場所に配置
set_target_properties(CppUtilities_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

# C++20 標準を使用
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CppUtilities_tests PROPERTY CXX_STANDARD 20)
endif()

# CTest でのテスト登録
enable_testing()
add_test(NAME CppUtilities_UnitTests COMMAND CppUtilities_tests)