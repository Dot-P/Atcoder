// 全探索008
// https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    LL n;
    cin >> n;
    vector<LL> A(n), B(n);
    rep(i, 0, n) cin >> A[i] >> B[i];

    LL ans = 1e12;
    rep(i, 0, n){
        rep(j, 0, n){
            LL time = 0;
            rep(k, 0, n){
                time += abs(A[k]-A[i]) + abs(A[k]-B[k]) + abs(B[k]-B[j]);
            }
            ans = min(ans, time);
        }
    }

    cout << ans << endl;
}