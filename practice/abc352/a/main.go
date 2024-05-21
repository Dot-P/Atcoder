package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func main() {
	// 標準入力から最大16MBのデータを読み込み可能なスキャナを作成
	scanner.Buffer(make([]byte, 1024), 16*1024*1024)
	scanner.Split(bufio.ScanWords)

	// 最後にフラッシュする
	defer flush()

	// 標準入力からデータを読み込み
	_, x, y, z := newIntScan4()

	if (x < z && z < y) || (y < z && z < x) {
		cout("Yes")
	} else {
		cout("No")
	}

}

/*   以下自作ライブラリ  */
func newIntScan1() int {
	scanner.Scan()
	i, e := strconv.Atoi(scanner.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func newIntScan2() (int, int) {
	return newIntScan1(), newIntScan1()
}

func newIntScan3() (int, int, int) {
	return newIntScan1(), newIntScan1(), newIntScan1()
}

func newIntScan4() (int, int, int, int) {
	return newIntScan1(), newIntScan1(), newIntScan1(), newIntScan1()
}

func flush() {
	e := writer.Flush()
	if e != nil {
		panic(e)
	}
}

func cout(v ...interface{}) {
	_, e := fmt.Fprintln(writer, v...)
	if e != nil {
		panic(e)
	}
}
