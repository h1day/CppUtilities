# コードスタイルと規約

## コードフォーマット (.clang-format)
- **ベーススタイル**: LLVM
- **インデント幅**: 4スペース
- **列制限**: 120文字
- **ブレース配置**: Custom (改行後に配置)
- **ポインタ配置**: Left alignment (`int* ptr`)
- **改行**: ファイル末尾に改行を挿入

### 主要なフォーマット設定
- `AccessModifierOffset: -4`
- `AlwaysBreakTemplateDeclarations: Yes`
- `BreakBeforeBraces: Custom`
- `IndentCaseBlocks: true`
- `NamespaceIndentation: All`

## 静的解析設定 (.clang-tidy)
### 有効化されたチェック
- `performance-*` - パフォーマンス関連
- `readability-*` - 可読性向上
- `modernize-*` - モダンC++機能推進
- `cppcoreguidelines-*` - C++コアガイドライン準拠

### 除外されたチェック
- `modernize-use-trailing-return-type`
- `readability-magic-numbers`
- `cppcoreguidelines-avoid-magic-numbers`
- `readability-identifier-length`
- `modernize-use-nodiscard`
- `modernize-use-auto`

### 主要な設定
- 関数の認知的複雑性閾値: 25
- 関数の行数閾値: 80
- `NULL`マクロを`nullptr`に変換

## コード規約
### ヘッダーファイル
- `#pragma once`を使用
- 標準ライブラリ（`<iostream>`など）をインクルード

### ネーミング
- 関数名: snake_case (`test_function`)
- 変数名: snake_case (`magic_number`)

### C++20機能
- 標準ライブラリのみ使用
- MSVCホットリロード機能対応
- 外部ライブラリ依存なし

### コメント
- 日本語コメントを使用
- アプリケーションエントリポイントなど重要箇所にコメント記載