# タスク完了時のチェックリスト

## コード変更後の必須チェック

### 1. ビルド確認
```cmd
# デバッグビルドで確認
cmake --preset x64-debug
cmake --build out/build/x64-debug --config Debug

# リリースビルドで確認
cmake --preset x64-release  
cmake --build out/build/x64-release --config Release
```

### 2. コードフォーマット適用
```cmd
# .clang-formatに基づくフォーマット
clang-format -i *.cpp *.h
```

### 3. 静的解析チェック
```cmd
# .clang-tidyに基づく静的解析
clang-tidy *.cpp *.h
```

### 4. 実行確認
```cmd
# デバッグ版での動作確認
out\build\x64-debug\CppUtilities.exe

# リリース版での動作確認
out\build\x64-release\CppUtilities.exe
```

## コード品質確認

### 静的解析対応
- magic numberの排除
- `NULL`を`nullptr`に変更
- 適切なスペーシング
- 未使用変数の削除
- 関数の複雑性チェック（閾値: 25）
- 関数サイズチェック（閾値: 80行）

### コードスタイル確認
- インデント: 4スペース
- 列制限: 120文字
- ブレース配置: Custom style
- ポインタ配置: Left alignment
- ファイル末尾改行の存在

## Git操作（必要に応じて）
```cmd
git add .
git commit -m "descriptive commit message"
# git push（必要な場合のみ）
```

## 注意事項
- テストフレームワーク未実装のため、手動実行での動作確認が必要
- VS Code使用時は必ずNative Tools Command Promptから起動
- CMakeプリセット（x64-debug/x64-release）の使用を推奨
- MSVCホットリロード機能を活用可能

## 最終確認
1. ✅ ビルドエラーなし（Debug/Release両方）
2. ✅ フォーマット適用済み
3. ✅ 静的解析警告対応済み  
4. ✅ 実行可能ファイルが正常動作
5. ✅ コミットメッセージが適切（必要な場合）