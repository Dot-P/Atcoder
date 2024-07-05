// 二分探索02
// https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
// 円の開始時点も加えること

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int binary_search(VI &D, int k){
    int l = 0;
    int r = D.size();
    while(r -l > 1){
        int mid = l + (r - l) / 2;
        if(D[mid] >= k) r = mid;
        else l = mid;
    }
    return r;
}

int main(void) {
    int d;
    cin >> d;
    int n, m;
    cin >> n >> m;
    VI D(n, 0), K(m);
    rep(i, 1, n) cin >> D[i];
    rep(i, 0, m) cin >> K[i];

    int ans = 0;
    D.push_back(d);
    sort(D.begin(), D.end());
    rep(i, 0, m){
        int r = binary_search(D, K[i]);
        ans += min(abs(D[r]-K[i]), abs(D[r-1]-K[i]));
    }

    cout << ans << endl;
}