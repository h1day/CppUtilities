// CppUTest テストファイル - ファイル処理のテスト
#include "CppUTest/TestHarness.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <iostream>

TEST_GROUP(FileHandlingTests)
{
    void setup() override
    {
        // テスト前の準備処理（必要に応じて）
    }
    
    void teardown() override
    {
        // テスト後のクリーンアップ処理（必要に応じて）
    }
};

TEST(FileHandlingTests, ReadCSVFileFromRelativePath)
{
    // テスト実行ファイルからの相対パスでCSVファイルを参照
    std::string relativePath = "testdata/data1.csv";
    
    // ファイルの存在確認
    std::ifstream file(relativePath);
    CHECK(file.is_open());
    
    if (!file.is_open()) {
        FAIL("Could not open test data file: testdata/data1.csv");
        return;
    }
    
    // ヘッダー行を読み込み
    std::string headerLine;
    std::getline(file, headerLine);
    STRCMP_EQUAL("name,age,city", headerLine.c_str());
    
    // データ行数をカウント
    std::vector<std::string> dataLines;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            dataLines.push_back(line);
        }
    }
    
    file.close();
    
    // 期待するデータ行数をチェック（4行のデータがあることを確認）
    CHECK_EQUAL(4, dataLines.size());
    
    // 各データ行の内容をチェック
    STRCMP_EQUAL("John,25,Tokyo", dataLines[0].c_str());
    STRCMP_EQUAL("Mary,30,Osaka", dataLines[1].c_str());
    STRCMP_EQUAL("Bob,35,Nagoya", dataLines[2].c_str());
    STRCMP_EQUAL("Alice,28,Kyoto", dataLines[3].c_str());
}

TEST(FileHandlingTests, CheckFileSystemOperations)
{
    std::string relativePath = "testdata/data1.csv";
    
    // std::filesystem を使用してファイルの存在を確認
    std::filesystem::path filePath(relativePath);
    CHECK(std::filesystem::exists(filePath));
    
    // ファイルサイズを取得
    auto fileSize = std::filesystem::file_size(filePath);
    CHECK(fileSize > 0);
    
    // ファイルが通常ファイルであることを確認
    CHECK(std::filesystem::is_regular_file(filePath));
}

TEST(FileHandlingTests, ParseCSVContent)
{
    std::string relativePath = "testdata/data1.csv";
    
    std::ifstream file(relativePath);
    CHECK(file.is_open());
    
    if (!file.is_open()) {
        FAIL("Could not open test data file");
        return;
    }
    
    // ヘッダーをスキップ
    std::string headerLine;
    std::getline(file, headerLine);
    
    // 最初のデータ行を解析
    std::string dataLine;
    std::getline(file, dataLine);

    
    // 簡単なCSV解析（カンマで分割）
    std::vector<std::string> fields;
    std::string field;
    std::stringstream ss(dataLine);
    
    while (std::getline(ss, field, ',')) {
        fields.push_back(field);
    }
    
    file.close();
    
    // フィールド数をチェック
    CHECK_EQUAL(3, fields.size());
    
    // 各フィールドの値をチェック
    STRCMP_EQUAL("John", fields[0].c_str());
    STRCMP_EQUAL("25", fields[1].c_str());
    STRCMP_EQUAL("Tokyo", fields[2].c_str());
}