package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	s := newStringScan()
	t := newStringScan()

	ans := make([]int, 0)

	cursol := 0
	for i := 0; i < len(t); i++ {
		if t[i] == s[cursol] {
			ans = append(ans, i+1)
			cursol++
		}
		if cursol > len(s)-1 {
			break
		}
	}

	outSlice(ans)

}

/*   以下自作ライブラリ  */
// スキャナー
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

func newStringScan() string {
	scanner.Scan()
	return scanner.Text()
}

// ライター
func flush() {
	e := writer.Flush()
	if e != nil {
		panic(e)
	}
}

func out(v ...interface{}) {
	_, e := fmt.Fprintln(writer, v...)
	if e != nil {
		panic(e)
	}
}

func outSlice(slice []int) {
	r := make([]string, len(slice))
	for i, v := range slice {
		r[i] = strconv.Itoa(v)
	}
	out(strings.Join(r, " "))
}
