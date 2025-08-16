// ベータテストグループ - 数値計算とコンテナ操作のテスト
#include "CppUTest/TestHarness.h"
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>

// ベータテストグループの定義
TEST_GROUP(BetaTestGroup)
{
    std::vector<double> float_data;
    std::map<std::string, int> test_map;

    void setup()
    {
        // テスト前の準備
        float_data = {1.5, 2.7, 3.14, 4.0, 5.5};
        test_map = {{"alpha", 1}, {"beta", 2}, {"gamma", 3}};
    }

    void teardown()
    {
        // テスト後のクリーンアップ
        float_data.clear();
        test_map.clear();
    }
};

// 数学関数のテスト
TEST(BetaTestGroup, MathFunctionsTest)
{
    double value = 16.0;
    double sqrt_result = std::sqrt(value);
    double pow_result = std::pow(2, 3);
    
    DOUBLES_EQUAL(4.0, sqrt_result, 0.001);
    DOUBLES_EQUAL(8.0, pow_result, 0.001);
}

// ベクターの累積計算テスト
TEST(BetaTestGroup, VectorAccumulateTest)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    
    CHECK_EQUAL(15, sum);
    CHECK_EQUAL(120, product);
}

// マップの操作テスト
TEST(BetaTestGroup, MapOperationsTest)
{
    std::map<int, std::string> id_map;
    id_map[100] = "Admin";
    id_map[200] = "User";
    id_map[300] = "Guest";
    
    CHECK_EQUAL(3, id_map.size());
    STRCMP_EQUAL("User", id_map[200].c_str());
    
    auto it = id_map.find(150);
    CHECK(it == id_map.end()); // 存在しないキー
}

// セットの操作テスト
TEST(BetaTestGroup, SetOperationsTest)
{
    std::set<int> numbers = {5, 1, 9, 3, 7, 1, 5}; // 重複あり
    
    CHECK_EQUAL(5, numbers.size()); // 重複は除去される
    CHECK(numbers.find(3) != numbers.end());
    CHECK(numbers.find(2) == numbers.end());
    
    // セットは自動的にソートされる
    auto it = numbers.begin();
    CHECK_EQUAL(1, *it);
}

// キューとスタックのテスト
TEST(BetaTestGroup, QueueStackTest)
{
    std::queue<int> q;
    std::stack<int> s;
    
    // キューのテスト (FIFO)
    q.push(10);
    q.push(20);
    q.push(30);
    
    CHECK_EQUAL(10, q.front());
    q.pop();
    CHECK_EQUAL(20, q.front());
    
    // スタックのテスト (LIFO)
    s.push(10);
    s.push(20);
    s.push(30);
    
    CHECK_EQUAL(30, s.top());
    s.pop();
    CHECK_EQUAL(20, s.top());
}

// 浮動小数点の計算テスト
TEST(BetaTestGroup, FloatingPointCalculationTest)
{
    double a = 0.1;
    double b = 0.2;
    double result = a + b;
    
    // 浮動小数点の精度を考慮した比較
    DOUBLES_EQUAL(0.3, result, 0.0001);
    
    // 平均値の計算
    double average = std::accumulate(float_data.begin(), float_data.end(), 0.0) / float_data.size();
    DOUBLES_EQUAL(3.368, average, 0.001);
}