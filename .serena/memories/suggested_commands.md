# 推奨コマンド一覧

## ビルドコマンド

### CMakeコマンド（推奨）
```cmd
# デバッグビルド
cmake --preset x64-debug
cmake --build out/build/x64-debug --config Debug

# リリースビルド  
cmake --preset x64-release
cmake --build out/build/x64-release --config Release
```

### VS Codeタスク
VS Code環境では以下のタスクが利用可能：
- `Build Debug` - デバッグビルド（デフォルト、Configure Debug自動実行）
- `Build Release` - リリースビルド（Configure Release自動実行）
- `Configure Debug` - デバッグ設定
- `Configure Release` - リリース設定
- `Clean Debug` - デバッグビルドファイルクリーンアップ
- `Clean Release` - リリースビルドファイルクリーンアップ

実行方法: `Ctrl+Shift+P` → `Tasks: Run Task`

## 開発環境セットアップ

### 重要: VS Code起動方法
```cmd
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
code "C:\work\CppUtilities"
```

## 実行コマンド
```cmd
# デバッグ版実行
out\build\x64-debug\CppUtilities.exe

# リリース版実行
out\build\x64-release\CppUtilities.exe
```

## コード品質コマンド
### フォーマット（要clang-format）
```cmd
clang-format -i CppUtilities.cpp CppUtilities.h
```

### 静的解析（要clang-tidy）
```cmd
clang-tidy CppUtilities.cpp CppUtilities.h
```

## Windows用ユーティリティコマンド
```cmd
# ファイル一覧
dir
dir /s      # 再帰的

# ファイル検索
findstr /s /i "pattern" *.cpp *.h

# プロセス確認
tasklist | findstr "process_name"

# パス確認
where cmake
where ninja
where cl

# ディレクトリ移動
cd path\to\directory

# ファイル削除/ディレクトリ削除
del filename
rmdir /s /q dirname
```

## Git操作
```cmd
git status
git add .
git commit -m "message"
git push origin branch_name
git pull
```

## 注意事項
- CMakeとNinjaがPATHに含まれている必要あり
- MSVCコンパイラ（cl.exe）がPATHに含まれている必要あり
- テストフレームワークは未実装（TODO状態）