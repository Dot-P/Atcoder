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

type graph struct {
	to_edge int
	weight  int
}

var ans = -1

func dfs(v int, G [][]graph, visited []bool, length int) {
	if visited[v] == true {
		return
	}
	visited[v] = true
	ans = max(ans, length)
	for _, edge := range G[v] {
		if !visited[edge.to_edge] {
			dfs(edge.to_edge, G, visited, length+edge.weight)
		}
	}
	visited[v] = false
}

func main() {
	// 標準入力から最大16MBのデータを読み込み可能なスキャナを作成
	scanner.Buffer(make([]byte, 1024), 16*1024*1024)
	scanner.Split(bufio.ScanWords)

	// 最後にフラッシュする
	defer flush()

	n, m := newIntScan2()
	a, b, c := newIntSliceScan3(m)

	G := make([][]graph, n)

	for idx := range a {
		G[a[idx]-1] = append(G[a[idx]-1], graph{b[idx] - 1, c[idx]})
		G[b[idx]-1] = append(G[b[idx]-1], graph{a[idx] - 1, c[idx]})
	}

	for i := 0; i < n; i++ {
		visited := make([]bool, n)
		dfs(i, G, visited, 0)
	}

	out(ans)

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

// Max関数、Min関数
func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func mix(a int, b int) int {
	if a > b {
		return b
	}
	return a
}
