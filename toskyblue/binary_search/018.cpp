// 二分探索01
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
// めぐる式二分探索は、常に左が満たさず、右をか必ず満たすようにする

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

bool isOK(VI s, int idx, int key){
    if(s[idx] >= key) return true;
    else return false;
}

int binary_search(VI s, int key){
    int left = -1;
    int right = s.size();
    while(right - left > 1){
        int mid = left + (left + right) / 2;
        if(isOK(s, mid, key)) right = mid;
        else left = mid;
    }
    return right;
}

int main(void) {
    int n;
    cin >> n;
    VI s(n);
    rep(i, 0, n) cin >> s[i];
    int q;
    cin >> q;
    VI t(n);
    rep(i, 0, q) cin >> t[i];

    int ans = 0;
    rep(i, 0, q){
        int idx = lower_bound(s.begin(), s.end(), t[i]) - s.begin();
        if(s[idx] == t[i]) ans++;
    }
    cout << ans << endl;
}