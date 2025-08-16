// 新しいテストグループ - 自動検出テスト
#include "CppUTest/TestHarness.h"
#include <vector>
#include <algorithm>
#include <numeric>

// 新しいテストグループの定義
TEST_GROUP(NewFeatureTests)
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

// 新しいテスト1
TEST(NewFeatureTests, AutoDiscoveryTest1)
{
    std::vector<int> data = {1, 2, 3, 4, 5};
    int sum = std::accumulate(data.begin(), data.end(), 0);
    CHECK_EQUAL(15, sum);
}

// 新しいテスト2
TEST(NewFeatureTests, AutoDiscoveryTest2)
{
    std::string text = "auto discovery";
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);
    STRCMP_EQUAL("AUTO DISCOVERY", text.c_str());
}