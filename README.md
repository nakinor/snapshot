## 微笑み方
こちらの[記事](http://sci.hateblo.jp/entry/Benchmarking2)の付録です。あらかじめ GitHub にあるこの[辞書](https://github.com/uakms/mto)を別途ダウンロード、もしくはクローンしておいてください。

    git clone https://github.com/uakms/mto.git mtodic

## Emacs での利用
27.0.50 で動作を確認しています。ブラグイン形式の [emacs-mto](http://github.com/uakms/emacs-mto) を使います。

## Vim での利用
8.0.1748 で動作を確認しています。ブラグイン形式の [vim-mto](http://github.com/uakms/vim-mto) を使います。

## 端末上での各種スクリプトの利用
辞書ディレクトリへのパスを環境変数から探すので、`export MTODIC="/Users/path/to/mtodic"` 等の絶対パスにて `MTODIC` を設定しておいてください。

環境変数が適切に設定されていればスクリプトをどこに置いても動くはずですが、とりあえず下記のコマンドはカレントディレクトリが snapshot/src であるとします。

### Python3
3.6.0 で動作確を認しています。

    python3 mto.py tradkana test/seed

### Ruby
2.6.0dev で動作を確認しています。また、mruby でも動作しますが、`mruby-io` と `mruby-env`、そして `mruby-regexp-pcre` もしくは `mruby-onig-regexp` を組み込んでビルドしておいてください。

    ruby mto.rb tradkana test/seed
    mruby mto.rb tradkana test/seed

### Perl5
5.18.2 で動作を確認しています。

    perl mto.pl tradkana test/seed

### Lua
5.3.4 で動作を確認しています。

    lua mto.lua tradkana test/seed

### Go
1.10.0 で動作を確認しています。

    go run mto.go tradkana test/seed

もしくは実行ファイルにして

    go build mto.go
    ./mto tradkana test/seed

### CSharp
momo 5.10.0 で動作を確認しています。

    mcs mto-mono.cs
    mono mto-mono.exe tradkana test/seed

### Objective-C
Xcode 8.0.0 で動作を確認しています。

    clang -framework Foundation osx/main.m osx/MTODict.m -o mto-objc
    ./mto-objc tradkana test/seed

### Swift
Apple Swift 3.0.2 で動作を確認しています。

    xcrun --sdk `xcrun --show-sdk-path` swiftc -o mto-swift mto.swift
    ./mto-swift tradkana test/seed

### C
Xcode 8.0.0 で動作を確認しています。

    clang mto.c -o mto-c
    ./mto-c tradkana test/seed

### C++
Xcode 8.0.0 で動作を確認しています。

    clang++ mto.cc -o mto-cc
    ./mto-cc tradkana test/seed

### Node.js
9.8.0 で動作を確認しています。

    node mto-node.js tradkana test/seed

### PHP
7.2.0 で動作を確認しています。

    php mto.php tradkana test/seed

### Gauche
0.9.6_pre6 で動作を確認しています。

    gosh mto.scm tradkana test/seed

### SBCL
1.4.6.85 で動作を確認しています。ライブラリの cl-ppcre-2.0.11 が必要です。

    sbcl --script mto-sbcl.lisp tradkana test/seed

### Clozure CL
1.11 で動作を確認しています。ライブラリの cl-ppcre-2.0.11 が必要です。

    ccl -load mto-ccl.lisp -eval '(quit)' -- dummy tradkana test/seed

### CLISP
2.47 での動作を確認しています(Panther on iBook にて)。ライブラリの cl-ppcre-2.0.7 が必要です。

    clisp mto-clisp.lisp tradkana test/seed

### Elixir
1.6.4 (Erlang/OTP 20.2) で動作を確認しています。

    elixir mto.exs tradkana test/seed

## その他のスクリプトについて
### Makefile
Golang, C, C++, C#, Objective-C, Clozure CL のようなコンパイル系のものをビルドするのが面倒なので作成しました。シェルスクリプトの方が良かったですね。

また、簡易的なテストやベンチマークもすることができます。これもシェルスクリプトの方が良かったかもしれませんけど。

### conv.go
引数で渡した辞書をチェックしたり数えたり JSON っぽく出力します。

    go run utils/conv.go -c mtodic/kana-jisyo

### jisyo-converter.rb
`conv.go` を作成する前に使っていたものです。カレントディレクトリに JSON ファイルが出力されます。

    ruby utils/jisyo-converter.rb

### word-count.sh
`conv.go` を作成する前に使っていたものです。辞書の要素数や簡易的なチェックをします。

    sh utils/word-count.sh

### mto.js
この[ページ](https://mto.herokuapp.com/js/pc.html)で利用している JavaScript です。実はこれが結構速かったりします。ブラウザのエンジンが優秀なのか、`split` and `join` が `replace` よりも速いからなのか。今はこればかり使っています。

### osx ディレクトリ
ごにょごにょ。IDE で作成したプロジェクトってどのファイルを公開していいのかわからないんだよね。プロファイルに本名とか書かれちゃってるし……

`MTOAppDelegate.h` と `MTOAppDelegate.m` と `MainMenu.xib` が Cocoa 用です。`MTODict.h` と `MTODict.m` と `main.m` が CUI 用です。

### win ディレクトリ
ガサガサッ。IDE で作成したプロジェクトってどのファイルを公開していいのかわからないんだよね。プロファイルに本名とか書かれちゃってるし……

`MtoGW.exe.config` と `MtoGW_Form1.cs` と `MtoGW_Form2.cs` と `MtoGW_Program.cs` が Visual Studio 2008 Express で作成した GUI 用のものです。`mtocs_Program.cs` は CUI 用です。
