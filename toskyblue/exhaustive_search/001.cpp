// 全探索001
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n, x;

    while(1){
        cin >> n >> x;
        if(n == 0 and x == 0) break;
        int cnt = 0;
        rep(i, 1, n+1){
            rep(j, i+1, n+1){
                if(j+1 <= (x-i-j) and (x-i-j) <= n) cnt++;
            }
        }
        cout << cnt << endl;
    }
}