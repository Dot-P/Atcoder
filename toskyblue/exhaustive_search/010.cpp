// 全探索010
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n;
    cin >> n;
    VI A(n);
    rep(i, 0, n) cin >> A[i];
    int q;
    cin >> q;
    VI m(q);
    rep(i, 0, q) cin >> m[i];

    set<int> S;
    rep(i, 0, (1<<n)){
        int num = 0;
        rep(j, 0, n){
            if(i&(1<<j)) num += A[j];
        }
        S.insert(num);
    }

    rep(i, 0, q){
        if(S.find(m[i])==S.end()) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}