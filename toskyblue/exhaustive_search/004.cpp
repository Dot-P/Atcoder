// 全探索004
// https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    LL N, M;
    cin >> N >> M;
    vector<vector<LL>> A(N, vector<LL> (M));
    rep(i, 0, N)rep(j, 0, M) cin >> A[i][j];

    LL ans=0;
    rep(i, 0, M){
        rep(j, i+1, M){
            LL score=0;
            rep(k, 0, N){
                score += max(A[k][i], A[k][j]);
            }
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
}