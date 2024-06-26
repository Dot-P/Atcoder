// 全探索012
// https://atcoder.jp/contests/abc002/tasks/abc002_4

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n, m;
    cin >> n >> m;
    VI X(m), Y(m);
    rep(i, 0, m) cin >> X[i] >> Y[i];

    vector<vector<bool>> G(n+1, vector<bool> (n+1));
    rep(i, 0, m){
        G[X[i]-1][Y[i]-1] = true;
        G[Y[i]-1][X[i]-1] = true;
    }

    int ans = 0;
    rep(msk, 0, (1 << n)){
        int t = bitset<32>(msk).count();
        if (t <= ans) continue;

        bool ok = true;
        rep(i, 0, n){
            rep(j, 0, i){
                if(msk >> i & msk >> j & 1 and !G[i][j]) ok = false;
            }
        }
        if(ok) ans = t;
    }

    cout << ans << endl;
}