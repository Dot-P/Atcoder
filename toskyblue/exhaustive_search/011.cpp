// 全探索011
// https://atcoder.jp/contests/abc128/tasks/abc128_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n, m;
    cin >> n >> m;
    VI k(m);
    VVI s(m, VI (n+1));
    VI p(m);
    rep(i, 0, m){
        cin >> k[i];
        rep(j, 0, k[i]) cin >> s[i][j];
    }
    rep(i, 0, m) cin >> p[i];

    int ans = 0;
    rep(i, 0, (1<<n)){
        bool flg = true;
        vector<bool> on(n, false);
        rep(j, 0, n){
            if(i&(1<<j)) on[j] = true;
        }
        rep(j, 0, m){
            int even = 0;
            rep(x, 0, k[j]){
                if(on[s[j][x]-1]) even++;
            }
            if(even%2 != p[j]) flg = false;
        }
        if(flg) ans++;
    }

    cout << ans << endl;

}