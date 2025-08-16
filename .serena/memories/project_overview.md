# CppUtilities プロジェクト概要

## プロジェクトの目的
- C++ユーティリティライブラリプロジェクト
- 現在は "Hello CMake" の基本実装を持つミニマルフレームワーク
- **CppUTestテストフレームワーク統合済み**（2025-08-16追加）
- 将来的な拡張に向けた準備段階

## 技術スタック
- **言語**: C++20
- **ビルドシステム**: CMake 3.20+ with Ninja Generator
- **コンパイラ**: MSVC (cl.exe) - MSVCホットリロード機能サポート
- **テストフレームワーク**: CppUTest（FetchContentで統合）
- **プラットフォーム**: Windows専用
- **ターゲット**: 
  - メイン実行ファイル: `CppUtilities.exe`
  - テスト実行ファイル: `CppUtilities_tests.exe`

## プロジェクト構造
```bash
CppUtilities/
├── CMakeLists.txt          # CMakeビルド設定（CppUTest統合済み）
├── CMakePresets.json       # x64-debug/x64-releaseプリセット
├── CppUtilities.cpp        # メインソースファイル
├── CppUtilities.h          # ヘッダーファイル（#pragma once）
├── tests/                  # テストディレクトリ（NEW）
│   ├── CMakeLists.txt      # テスト用CMake設定
│   ├── test_main.cpp       # CppUTestテストランナー
│   └── test_utilities.cpp  # テストケース実装
├── .vscode/                # VS Code設定
│   ├── settings.json       # CMake + CppUTest Adapter設定
│   ├── launch.json         # デバッグ設定（テストデバッグ含む）
│   └── tasks.json          # ビルドタスク（テストビルド含む）
├── .clang-format          # コードフォーマット設定
├── .clang-tidy            # 静的解析設定
├── Folder.DotSettings     # ReSharperコードインスペクション設定
├── CLAUDE.md              # Claude Code用指示書
└── README.md              # 日本語ドキュメント（テスト説明含む）
```

## ビルド出力
- **メイン実行ファイル**:
  - デバッグ版: `out/build/x64-debug/CppUtilities.exe`
  - リリース版: `out/build/x64-release/CppUtilities.exe`
- **テスト実行ファイル**:
  - デバッグ版: `out/build/x64-debug/tests/CppUtilities_tests.exe`

## テスト環境
- **フレームワーク**: CppUTest (master branch via FetchContent)
- **テストグループ**: CppUtilitiesBasicTests
- **現在のテスト**: BasicMathTest, StringTest, OutputTest
- **VS Code統合**: CppUTest Test Adapter使用
- **実行方法**: コマンドライン、CTest、VS Code Test Explorer、デバッグ実行

## 重要な制約
- Visual Studio 2022環境が必須
- VS Codeは「x64 Native Tools Command Prompt for VS 2022」から起動必要
- MSVCコンパイラがPATHに存在することが前提
- CppUTest Test Adapter拡張機能必要（テスト機能使用時）