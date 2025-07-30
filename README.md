# CppUtilities

C++ユーティリティライブラリプロジェクト

## プロジェクト仕様
- C++20標準を使用
- MSVCコンパイラのホットリロード機能をサポート
- 実行可能ファイルターゲット: CppUtilities.exe

## 開発環境

### 必要な環境
- Visual Studio 2022 Community/Professional/Enterprise
- CMake 3.20以上
- Ninja Build System

### Visual Studio 2022でのビルド
1. Visual Studio 2022でプロジェクトフォルダを開く
2. CMakeプリセット「x64 Debug」または「x64 Release」を選択
3. ビルド実行

### VS Codeでのビルド

#### 重要: 環境設定
VS Codeは必ず「x64 Native Tools Command Prompt for VS 2022」から起動してください：

```cmd
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
code "C:\work\CppUtilities"
```

#### VS Code拡張機能
以下の拡張機能をインストール：
- C/C++ (Microsoft) - デバッグ用（IntelliSenseは無効）
- CMake Tools (Microsoft)
- clangd (LLVM) - 高性能IntelliSense・コード解析

#### ビルド手順
1. VS Codeでプロジェクトフォルダを開く
2. `Ctrl+Shift+P` → `CMake: Configure`
3. `Ctrl+Shift+P` → `CMake: Build`

#### タスクの実行
VS Codeでタスクを実行する方法：

1. **コマンドパレット経由**
   - `Ctrl+Shift+P` → `Tasks: Run Task`
   - 実行したいタスクを選択（Build Debug、Build Release、Clean等）

2. **ショートカットキー**
   - `Ctrl+Shift+P` → `Tasks: Run Build Task` (デフォルトビルドタスク)

3. **利用可能なタスク**
   - `Build Debug` - デバッグビルド実行（デフォルト、Configure Debug自動実行）
   - `Build Release` - リリースビルド実行（Configure Release自動実行）  
   - `Configure Debug` - デバッグ設定
   - `Configure Release` - リリース設定
   - `Clean Debug` - デバッグビルドファイルクリーンアップ
   - `Clean Release` - リリースビルドファイルクリーンアップ

#### デバッグ
- `F5`でデバッグ実行（自動的にBuild Debugが実行される）
- Debug/Release両方の起動設定が利用可能
- ブレークポイント設定可能
- 外部ターミナルでの実行

### プロジェクト構成
```plaintext
CppUtilities/
├── CMakeLists.txt          # CMakeビルド設定
├── CMakePresets.json       # CMakeプリセット定義
├── CppUtilities.cpp        # メインソースファイル
├── CppUtilities.h          # ヘッダーファイル
├── .clang-format           # コードフォーマット設定
├── .clang-tidy             # コード品質チェック設定
├── .vscode/
│   ├── settings.json       # VS Code clangd設定
│   ├── launch.json         # デバッグ設定（Debug/Release対応）
│   └── tasks.json          # ビルドタスク設定（依存関係設定済み）
└── out/build/              # ビルド出力ディレクトリ
```

### ビルド出力
- デバッグ版: `out/build/x64-debug/CppUtilities.exe`
- リリース版: `out/build/x64-release/CppUtilities.exe`

## ReSharper C++ 連携

### 概要
Visual StudioのReSharper C++と同等のコード品質チェックをVS Codeで実現できます。

### 設定内容
- **clangd**: Microsoft C++ IntelliSenseに代わる高性能言語サーバー
- **clang-tidy**: ReSharper C++と同等のコード検査ルール
- **Claude Code連携**: エディタ上の警告をリアルタイムで検出・活用

### 利用方法
1. **自動有効化**: プロジェクトを開くとclangdが自動起動
2. **リアルタイム検査**: コード入力時に警告が表示
3. **修正提案**: 一部の問題は自動修正可能（💡アイコン）
4. **Claude Code統合**: AI支援でコード品質向上

### ReSharper設定共有
- `.clang-tidy`: コード品質チェックルール
- `.clang-format`: コードフォーマット設定
- Visual StudioとVS Codeで同一基準のコード品質管理

### 検出される警告例
- `Use nullptr` instead of NULL
- `Use '\n'` instead of endl  
- 未使用変数の検出
- 関数のstatic化提案
- モダンC++構文の推奨
- パフォーマンス改善提案

### clangd機能
- **高速IntelliSense**: 定義ジャンプ・参照検索が瞬時
- **正確な補完**: リアルパーサーによる高精度補完
- **引数プレースホルダー無効**: 効率的なコーディング
- **IWYU統合**: 不要ヘッダー検出