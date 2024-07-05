// 全探索016
// https://atcoder.jp/contests/abc150/tasks/abc150_c
// vectorの比較は簡単に行える。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n;
    cin >> n;
    VI P(n), Q(n);
    rep(i, 0, n) cin >> P[i];
    rep(i, 0, n) cin >> Q[i];

    VI per;
    rep(i, 1, n+1) per.push_back(i);

    int p, q;
    int cnt = 0;
    do {
        cnt++;
        if (per == P) p = cnt;
        if (per == Q) q = cnt; 
    } while (next_permutation(per.begin(), per.end()));

    cout << abs(p - q) << endl;
    
}
