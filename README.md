# atcoderコマンドの使用方法

現在、C++とGo、Rustで使用することができます。
(2024/7/17: Rustに対応しました)

## テンプレートの作成
```bash
$ atcoder new abc001 cpp
```

## テストケースの実行
```bash
$ atcoder test
```

## テストケースの提出
```bash
$ atcoder submit
```

![Gopher](./Gopher.png)


# (参考) atcoderコマンドの設定方法
atcoder-cli、online-judge-toolsがインストールされていることを前提とします。

## 実行権限を与える
```bash
$ chmod +x atcoder.sh
```

## スクリプトのパスを通す
```bash
$ sudo mv atcoder.sh /usr/local/bin/atcoder
```