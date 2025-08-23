# CppUTest自動検出スクリプト（階層化対応版）
# Usage: cmake -DTEST_EXECUTABLE=path -P CppUTestDiscovery.cmake
# 出力形式: add_test(NAME cpputest:GroupName/TestName COMMAND ...)

if(NOT TEST_EXECUTABLE)
    message(FATAL_ERROR "TEST_EXECUTABLE must be defined")
endif()

if(NOT OUTPUT_FILE)
    set(OUTPUT_FILE "DiscoveredTests.cmake")
endif()

# テスト実行可能ファイル名を抽出（パスから）
get_filename_component(TEST_EXECUTABLE_NAME "${TEST_EXECUTABLE}" NAME)

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
    
    set(DISCOVERED_TESTS "# Auto-discovered CppUTest tests (hierarchical naming)\n")
    set(GROUPS_ADDED "")
    
    foreach(LINE ${TEST_LINES})
        # GroupName.TestName.FilePath.LineNumber を解析
        if(LINE MATCHES "^([^.]+)\\.([^.]+)\\..*")
            set(GROUP_NAME "${CMAKE_MATCH_1}")
            set(TEST_NAME "${CMAKE_MATCH_2}")
            
            # グループテスト（全体実行）をまだ追加していない場合は追加
            string(FIND "${GROUPS_ADDED}" "${GROUP_NAME};" GROUP_FOUND)
            if(GROUP_FOUND EQUAL -1)
                string(APPEND DISCOVERED_TESTS "add_test(NAME cpputest:${GROUP_NAME} COMMAND ${TEST_EXECUTABLE_NAME} -sg ${GROUP_NAME})\n")
                string(APPEND GROUPS_ADDED "${GROUP_NAME};")
            endif()
            
            # 個別テストを階層化命名で追加
            string(APPEND DISCOVERED_TESTS "add_test(NAME cpputest:${GROUP_NAME}/${TEST_NAME} COMMAND ${TEST_EXECUTABLE_NAME} -sg ${GROUP_NAME} -sn ${TEST_NAME})\n")
        endif()
    endforeach()
    
    # 発見されたテストをファイルに出力
    file(WRITE "${OUTPUT_FILE}" "${DISCOVERED_TESTS}")
    
    message(STATUS "CppUTest Discovery: Successfully generated ${OUTPUT_FILE} with hierarchical test naming")
else()
    message(WARNING "CppUTest Discovery: Failed to run test executable (${TEST_DISCOVERY_RESULT})")
    message(WARNING "Error output: ${TEST_LIST_ERROR}")
    # 空のファイルを作成して後続処理でエラーにならないようにする
    file(WRITE "${OUTPUT_FILE}" "# Auto-discovery failed\n")
endif()