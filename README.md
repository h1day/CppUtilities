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
- C/C++ (Microsoft)
- CMake Tools (Microsoft)

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
   - `Build Debug` - デバッグビルド実行
   - `Build Release` - リリースビルド実行  
   - `Configure Debug` - デバッグ設定
   - `Clean` - ビルドファイルクリーンアップ

#### デバッグ
- `F5`でデバッグ実行
- ブレークポイント設定可能

### プロジェクト構成
```plaintext
CppUtilities/
├── CMakeLists.txt          # CMakeビルド設定
├── CMakePresets.json       # CMakeプリセット定義
├── CppUtilities.cpp        # メインソースファイル
├── CppUtilities.h          # ヘッダーファイル
├── .vscode/
│   ├── settings.json       # VS Code CMake設定
│   ├── launch.json         # デバッグ設定
│   └── tasks.json          # ビルドタスク設定
└── out/build/              # ビルド出力ディレクトリ
```

### ビルド出力
- デバッグ版: `out/build/x64-debug/CppUtilities.exe`
- リリース版: `out/build/x64-release/CppUtilities.exe`