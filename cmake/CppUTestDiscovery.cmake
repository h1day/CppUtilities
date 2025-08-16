# CppUTest自動検出スクリプト
# Usage: cmake -DTEST_EXECUTABLE=path -P CppUTestDiscovery.cmake

if(NOT TEST_EXECUTABLE)
    message(FATAL_ERROR "TEST_EXECUTABLE must be defined")
endif()

if(NOT OUTPUT_FILE)
    set(OUTPUT_FILE "DiscoveredTests.cmake")
endif()

# テスト一覧を取得
execute_process(
    COMMAND "${TEST_EXECUTABLE}" -ll
    OUTPUT_VARIABLE TEST_LIST_OUTPUT
    ERROR_VARIABLE TEST_LIST_ERROR
    RESULT_VARIABLE TEST_DISCOVERY_RESULT
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_STRIP_TRAILING_WHITESPACE
)

if(TEST_DISCOVERY_RESULT EQUAL 0)
    # テスト出力を解析 (GroupName.TestName.FilePath.LineNumber 形式)
    string(REPLACE "\n" ";" TEST_LINES "${TEST_LIST_OUTPUT}")
    
    set(DISCOVERED_TESTS "# Auto-discovered CppUTest tests\n")
    set(GROUPS_ADDED "")
    
    foreach(LINE ${TEST_LINES})
        # GroupName.TestName.FilePath.LineNumber を解析
        if(LINE MATCHES "^([^.]+)\\.([^.]+)\\..*")
            set(GROUP_NAME "${CMAKE_MATCH_1}")
            set(TEST_NAME "${CMAKE_MATCH_2}")
            
            # グループをまだ追加していない場合は追加
            string(FIND "${GROUPS_ADDED}" "${GROUP_NAME};" GROUP_FOUND)
            if(GROUP_FOUND EQUAL -1)
                string(APPEND DISCOVERED_TESTS "add_test(NAME ${GROUP_NAME}_Group COMMAND CppUtilities_tests -sg ${GROUP_NAME})\n")
                string(APPEND GROUPS_ADDED "${GROUP_NAME};")
            endif()
            
            # 個別テストを追加
            string(APPEND DISCOVERED_TESTS "add_test(NAME ${GROUP_NAME}_${TEST_NAME} COMMAND CppUtilities_tests -sg ${GROUP_NAME} -sn ${TEST_NAME})\n")
        endif()
    endforeach()
    
    # 発見されたテストをファイルに出力
    file(WRITE "${OUTPUT_FILE}" "${DISCOVERED_TESTS}")
    
    message(STATUS "CppUTest Discovery: Successfully generated ${OUTPUT_FILE}")
else()
    message(WARNING "CppUTest Discovery: Failed to run test executable (${TEST_DISCOVERY_RESULT})")
    message(WARNING "Error output: ${TEST_LIST_ERROR}")
    # 空のファイルを作成して後続処理でエラーにならないようにする
    file(WRITE "${OUTPUT_FILE}" "# Auto-discovery failed\n")
endif()