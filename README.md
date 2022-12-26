# Xmas mini_mini_shell
このプロジェクトは， 12/24 日に シェルをつくろうというものです。knitta と satushi によるペアプログラミングで挑みます。

# 要件
### 使用可能関数
```
readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, **access**, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, **sigemptyset, sigaddset**, kill, exit, **getcwd**, chdir, **stat, lstat, fstat**, **unlink**, execve, **strerror, perror**, **isatty, ttyname, ttyslot**, **ioctl**, getenv, **tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs**
```

# 機能要件
- プロンプトを表示して，コマンドの入力をまつ
- ヒストリーの機能をもつ
- PATH環境変数に登録されたパス,または,絶対パス，相対パスの指定に従って，実行可能ファイルを探しに行って，実行できる
- グローバル変数をプログラムの中で，一つまでしか使わないこと
- Not interpret unclosed quotes or special characters which are not required by the subject such as \(backslash) or ;(semicolon).
- ' ' (シングルクオーテーション)で囲まれた部分については，その内部に含まれる **特殊文字**について,シェルによる解釈をすべきではない。
- " " (ダブルクオーテーション)の場合も上に同じであるが，`$`(dollar sign)については，解釈する。




疲れたので，ここまで！！☆





`readline()`関数はメモリリークを起こしうる。これについては対応しなくて良い。しかし，実装コードの中でのメモリリークは許されない。

**bash が 最終的なリファレンスであるので，　自分達の解釈を常に bash の挙動と比較して確認すること！**
