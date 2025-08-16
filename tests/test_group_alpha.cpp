// アルファテストグループ - 文字列処理とファイル操作のテスト
#include "CppUTest/TestHarness.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

// アルファテストグループの定義
TEST_GROUP(AlphaTestGroup)
{
    std::string test_data;
    std::vector<int> test_numbers;

    void setup()
    {
        // テスト前の準備
        test_data = "Sample Test Data";
        test_numbers = {1, 2, 3, 4, 5};
    }

    void teardown()
    {
        // テスト後のクリーンアップ
        test_data.clear();
        test_numbers.clear();
    }
};

// 文字列の変換テスト
TEST(AlphaTestGroup, StringTransformationTest)
{
    std::string original = "hello world";
    std::transform(original.begin(), original.end(), original.begin(), ::toupper);
    
    STRCMP_EQUAL("HELLO WORLD", original.c_str());
}

// 文字列の検索テスト
TEST(AlphaTestGroup, StringSearchTest)
{
    std::string text = "This is a sample text for testing";
    size_t found = text.find("sample");
    
    CHECK(found != std::string::npos);
    CHECK_EQUAL(10, found);
}

// ベクターの操作テスト
TEST(AlphaTestGroup, VectorOperationTest)
{
    std::vector<int> numbers = {5, 2, 8, 1, 9};
    std::sort(numbers.begin(), numbers.end());
    
    CHECK_EQUAL(1, numbers[0]);
    CHECK_EQUAL(9, numbers[4]);
    CHECK_EQUAL(5, numbers.size());
}

// 文字列分割テスト
TEST(AlphaTestGroup, StringSplitTest)
{
    std::string input = "one,two,three,four";
    std::vector<std::string> tokens;
    std::istringstream iss(input);
    std::string token;
    
    while (std::getline(iss, token, ',')) {
        tokens.push_back(token);
    }
    
    CHECK_EQUAL(4, tokens.size());
    STRCMP_EQUAL("one", tokens[0].c_str());
    STRCMP_EQUAL("four", tokens[3].c_str());
}

// アルゴリズムテスト - find_if
TEST(AlphaTestGroup, AlgorithmFindIfTest)
{
    std::vector<int> numbers = {2, 4, 7, 8, 10};
    
    auto it = std::find_if(numbers.begin(), numbers.end(), 
                          [](int n) { return n % 2 == 1; }); // 奇数を検索
    
    CHECK(it != numbers.end());
    CHECK_EQUAL(7, *it);
}