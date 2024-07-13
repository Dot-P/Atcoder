// 二分探索04
// https://atcoder.jp/contests/abc023/tasks/abc023_d
// 答えを決め打ちする系の二分探索、判定が難しい

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

LL n;
vector<LL> H(1e6), S(1e6);

bool ok (LL x){
    vector<LL> t;
    rep(i, 0, n){
        if(x - H[i] < 0) return false; 
        LL time_limit = (x - H[i])/S[i];
        t.push_back(time_limit);
    }
    sort(t.begin(), t.end());
    rep(i, 0, n){
        if(t[i] < i) return false;
    }
    return true;
}

int main(void) {
    cin >> n;
    rep(i, 0, n) cin >> H[i] >> S[i];

    LL left = -1, right = 1e16;
    while(right - left > 1){
        LL mid = left + (right - left) / 2;
        if(ok(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}