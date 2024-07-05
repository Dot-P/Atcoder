// 全探索015
// https://atcoder.jp/contests/abc145/tasks/abc145_c
// next_permutationを使用した巡回セールスマン問題

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int n;
    cin >> n;
    VI x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    VI pass;
    rep(i, 0, n) pass.push_back(i);
    
    double ans = 0;
    int cnt = 0;
    do{
        cnt++;
        rep(i, 0, pass.size()-1) ans += sqrt((double)(x[pass[i+1]]-x[pass[i]])*(x[pass[i+1]]-x[pass[i]])+(y[pass[i+1]]-y[pass[i]])*(y[pass[i+1]]-y[pass[i]]));
    }while(next_permutation(pass.begin(), pass.end()));

    cout << setprecision(12) << ans/cnt << endl;
}