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
	n, h, x := newIntScan3()
	p := newIntSliceScan(n)

	// 処理
	for idx, diff := range p {
		if h+diff >= x {
			out(idx + 1)
			break
		}
	}

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

func newIntSliceScan(n int) []int {
	a := make([]int, 0, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		number, err := strconv.Atoi(scanner.Text())
		if err != nil {
			panic(err)
		}
		a = append(a, number)
	}
	return a
}

func newIntSliceScan2(n int) ([]int, []int) {
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], b[i] = newIntScan2()
	}
	return a, b
}

func newIntSliceScan3(n int) ([]int, []int, []int) {
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], b[i], c[i] = newIntScan3()
	}
	return a, b, c
}

func newIntSliceScan4(n int) ([]int, []int, []int, []int) {
	a := make([]int, n)
	b := make([]int, n)
	c := make([]int, n)
	d := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], b[i], c[i], d[i] = newIntScan4()
	}
	return a, b, c, d
}

func newStringScan() string {
	scanner.Scan()
	return scanner.Text()
}

// ライター
func flush() {
	err := writer.Flush()
	if err != nil {
		panic(err)
	}
}

func out(v ...interface{}) {
	_, err := fmt.Fprintln(writer, v...)
	if err != nil {
		panic(err)
	}
}

func outSlice(slice []int) {
	r := make([]string, len(slice))
	for i, v := range slice {
		r[i] = strconv.Itoa(v)
	}
	out(strings.Join(r, " "))
}
