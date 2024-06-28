// 全探査013
// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e
// ビット全探索することのできる範囲を考えるのが重要

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n, m;
    cin >> n >> m;
    VVI senbei(n, VI (m));
    rep(i, 0, n)rep(j, 0, m) cin >> senbei[i][j];

    int ans = 0;
    rep(i, 0, (1 << n)){
        int now = 0;
        VVI item = senbei;
        rep(j, 0, n){
            if(i & (1 << j)){
                rep(k, 0, m) item[j][k] = 1 - item[j][k];
            }
        }
        rep(j, 0, m){
            int cnt = 0;
            rep(k, 0, n){
                if(item[k][j] == 1) cnt++;
            }
            now += max(cnt, n-cnt);
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
}