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
- CppUTest Test Adapter (Benjamin Neumann) - テスト実行・デバッグ用

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
   - `Build Tests` - テストのみビルド実行
   - `Configure Debug` - デバッグ設定
   - `Configure Release` - リリース設定
   - `Clean Debug` - デバッグビルドファイルクリーンアップ
   - `Clean Release` - リリースビルドファイルクリーンアップ

#### デバッグ
- `F5`でデバッグ実行（自動的にBuild Debugが実行される）
- Debug/Release両方の起動設定が利用可能
- ブレークポイント設定可能
- 外部ターミナルでの実行

## テスト

このプロジェクトはCppUTestフレームワークを使用してユニットテストを実装しています。

### テスト構成
```plaintext
tests/
├── CMakeLists.txt           # テスト用CMake設定
├── test_main.cpp            # CppUTestテストランナー
└── test_utilities.cpp       # 基本的なテストケース
```

### テスト実行方法

#### 1. コマンドライン実行
```bash
# プロジェクトビルド（テストも含む）
cmake --preset x64-debug
cmake --build out/build/x64-debug --config Debug

# 直接テスト実行
out/build/x64-debug/tests/CppUtilities_tests.exe

# CTest経由でのテスト実行
cd out/build/x64-debug
ctest --verbose
```

#### 2. VS Code Test Explorer
1. **CppUTest Test Adapter拡張機能**をインストール
2. VS CodeのTestingパネル（左側のテストアイコン）を開く
3. テストが自動検出され、階層表示される
4. 個別テストまたはグループ単位での実行が可能
5. テスト結果がリアルタイムで表示される

**テスト検出の仕組み:**
- アダプターは設定された`preLaunchTask`（Build Debug）を実行してテスト実行ファイルをビルド
- ビルド後、`CppUtilities_tests.exe -ll`コマンドでテスト一覧を取得
- 取得したテスト情報をもとにTest Explorerで階層表示（テストグループ→個別テスト）
- テスト実行時は`-g <グループ名> -n <テスト名>`引数で特定テストを実行

`-ll`オプションの出力例：
```bash
CppUtilitiesBasicTests.OutputTest.C:\work\CppUtilities\tests\test_utilities.cpp.38
CppUtilitiesBasicTests.StringTest.C:\work\CppUtilities\tests\test_utilities.cpp.28
CppUtilitiesBasicTests.BasicMathTest.C:\work\CppUtilities\tests\test_utilities.cpp.21
```
形式: `テストグループ.テスト名.ファイルパス.行番号`

#### 3. VS Codeデバッグ実行
`F5` → デバッグ設定を選択：

- **(Windows) Debug Tests** - 全テストをデバッグ実行
- **(Windows) Debug Single Test** - 特定テストをデバッグ実行
  - 実行時にテストグループ名とテスト名を入力プロンプトで指定

#### 4. CppUTestコマンドライン引数
CppUTestの主要なコマンドライン引数：
```bash
# テスト一覧を表示（Test Adapterが使用）
CppUtilities_tests.exe -ll

# 特定のテストグループのみ実行
CppUtilities_tests.exe -g CppUtilitiesBasicTests

# 特定のテストのみ実行  
CppUtilities_tests.exe -g CppUtilitiesBasicTests -n BasicMathTest

# 詳細出力
CppUtilities_tests.exe -v

# すべてのオプション表示
CppUtilities_tests.exe -h
```

### 現在のテストケース
- **BasicMathTest** - 基本的な数学演算のテスト
- **StringTest** - 文字列操作のテスト
- **OutputTest** - 標準出力のテスト（リダイレクト検証）

### 新しいテストの追加
1. `tests/test_utilities.cpp`にテストケースを追加
2. CppUTestの`TEST_GROUP`と`TEST`マクロを使用
3. ビルド後、自動的にTest Explorerに反映される

### プロジェクト構成
```plaintext
CppUtilities/
├── CMakeLists.txt          # CMakeビルド設定（CppUTest統合済み）
├── CMakePresets.json       # CMakeプリセット定義
├── CppUtilities.cpp        # メインソースファイル
├── CppUtilities.h          # ヘッダーファイル
├── tests/                  # テストディレクトリ
│   ├── CMakeLists.txt      # テスト用CMake設定
│   ├── test_main.cpp       # CppUTestテストランナー
│   └── test_utilities.cpp  # テストケース実装
├── .vscode/
│   ├── settings.json       # VS Code設定（CMake + CppUTest Adapter）
│   ├── launch.json         # デバッグ設定（テストデバッグ含む）
│   └── tasks.json          # ビルドタスク設定（テストビルド含む）
└── out/build/              # ビルド出力ディレクトリ
    └── x64-debug/tests/    # テスト実行ファイル
```

### ビルド出力
- **メインプログラム**:
  - デバッグ版: `out/build/x64-debug/CppUtilities.exe`
  - リリース版: `out/build/x64-release/CppUtilities.exe`
- **テスト実行ファイル**:
  - デバッグ版: `out/build/x64-debug/tests/CppUtilities_tests.exe`
