// 二分探索03
// https://atcoder.jp/contests/abc077/tasks/arc084_a
// 真ん中を基準にできるかが鍵

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n;
    cin >> n;
    VI A(n), B(n), C(n);
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, n) cin >> B[i];
    rep(i, 0, n) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int ans = 0;
    rep(i, 0, n){
        int bigger = n - (upper_bound(C.begin(), C.end(), B[i])-C.begin());
        int smaller = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ans += bigger * smaller;
    }

    cout << ans << endl;
}