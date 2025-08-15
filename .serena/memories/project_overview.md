# CppUtilities プロジェクト概要

## プロジェクトの目的
- C++ユーティリティライブラリプロジェクト
- 現在は "Hello CMake" の基本実装を持つミニマルフレームワーク
- 将来的な拡張に向けた準備段階

## 技術スタック
- **言語**: C++20
- **ビルドシステム**: CMake 3.20+ with Ninja Generator
- **コンパイラ**: MSVC (cl.exe) - MSVCホットリロード機能サポート
- **プラットフォーム**: Windows専用
- **ターゲット**: 単一実行ファイル `CppUtilities.exe`

## プロジェクト構造
```bash
CppUtilities/
├── CMakeLists.txt          # CMakeビルド設定
├── CMakePresets.json       # x64-debug/x64-releaseプリセット
├── CppUtilities.cpp        # メインソースファイル
├── CppUtilities.h          # ヘッダーファイル（#pragma once）
├── .clang-format          # コードフォーマット設定
├── .clang-tidy            # 静的解析設定
├── Folder.DotSettings     # ReSharperコードインスペクション設定
├── CLAUDE.md              # Claude Code用指示書
└── README.md              # 日本語ドキュメント
```

## ビルド出力
- デバッグ版: `out/build/x64-debug/CppUtilities.exe`
- リリース版: `out/build/x64-release/CppUtilities.exe`

## 重要な制約
- Visual Studio 2022環境が必須
- VS Codeは「x64 Native Tools Command Prompt for VS 2022」から起動必要
- MSVCコンパイラがPATHに存在することが前提