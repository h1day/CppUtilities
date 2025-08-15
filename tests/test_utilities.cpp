// CppUtilities の基本テスト
#include "CppUTest/TestHarness.h"
#include <iostream>
#include <sstream>

// テストグループの定義
TEST_GROUP(CppUtilitiesBasicTests)
{
    void setup()
    {
        // テスト前の準備
    }

    void teardown()
    {
        // テスト後のクリーンアップ
    }
};

// 基本的な数学演算のテスト
TEST(CppUtilitiesBasicTests, BasicMathTest)
{
    int result = 2 + 2;
    CHECK_EQUAL(4, result);
}

// 文字列操作のテスト
TEST(CppUtilitiesBasicTests, StringTest)
{
    std::string hello = "Hello";
    std::string world = "World";
    std::string result = hello + " " + world;
    
    STRCMP_EQUAL("Hello World", result.c_str());
}

// 標準出力のテスト（リダイレクト）
TEST(CppUtilitiesBasicTests, OutputTest)
{
    // 標準出力をキャプチャ
    std::ostringstream captured_output;
    std::streambuf* original = std::cout.rdbuf();
    std::cout.rdbuf(captured_output.rdbuf());
    
    // テスト対象の出力
    std::cout << "Hello CMake.";
    
    // 標準出力を復元
    std::cout.rdbuf(original);
    
    // 出力内容を検証
    CHECK(captured_output.str().find("Hello CMake.") != std::string::npos);
}