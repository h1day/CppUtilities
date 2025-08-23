# テスト用の CMakeLists.txt
# CppUTestの自動テスト検出機能付き

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

# テスト自動検出用のヘルパー関数
function(discover_cpputest_tests)
    # ビルド完了後に自動検出スクリプトを実行
    add_custom_command(
        TARGET CppUtilities_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} 
            -DTEST_EXECUTABLE=$<TARGET_FILE:CppUtilities_tests>
            -DOUTPUT_FILE=${CMAKE_CURRENT_BINARY_DIR}/DiscoveredTests.cmake
            -P ${CMAKE_SOURCE_DIR}/cmake/CppUTestDiscovery.cmake
        COMMENT "Auto-discovering CppUTest tests"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endfunction()

# テストディスカバリー実行  
discover_cpputest_tests()

# CTest でのテスト登録 - 真の自動検出実装

# 全体テスト実行（常に利用可能）
add_test(NAME AllTests COMMAND CppUtilities_tests)

# ビルド時に自動検出されたテストを含める
set(DISCOVERED_TESTS_FILE "${CMAKE_CURRENT_BINARY_DIR}/DiscoveredTests.cmake")
if(EXISTS "${DISCOVERED_TESTS_FILE}")
    include("${DISCOVERED_TESTS_FILE}")
    message(STATUS "Including auto-discovered tests from ${DISCOVERED_TESTS_FILE}")
else()
    # フォールバック：手動でテストを登録
    message(STATUS "Auto-discovery not available, using manual test registration")
    
    # 個別テストグループの登録
    add_test(NAME CppUtilitiesBasicTests 
             COMMAND CppUtilities_tests -sg CppUtilitiesBasicTests)

    # 個別テストケースの登録（主要なテスト）
    add_test(NAME BasicMathTest 
             COMMAND CppUtilities_tests -sg CppUtilitiesBasicTests -sn BasicMathTest)

    add_test(NAME StringTest 
             COMMAND CppUtilities_tests -sg CppUtilitiesBasicTests -sn StringTest)

    add_test(NAME OutputTest 
             COMMAND CppUtilities_tests -sg CppUtilitiesBasicTests -sn OutputTest)

   endif()
