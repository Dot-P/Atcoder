// 全探索009
// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int m, n;
    cin >> m;
    VI mx(m), my(m);
    rep(i, 0, m) cin >> mx[i] >> my[i];
    cin >> n;
    VI nx(n), ny(n);
    rep(i, 0, n) cin >> nx[i] >> ny[i];

    set<pair<int, int>> S;
    rep(i, 0, n) S.insert(make_pair(nx[i], ny[i]));
    rep(i, 0, n){
        int x = nx[i]-mx[0];
        int y = ny[i]-my[0];
        // cout << ">> " << x << " " << y << endl;
        // m個の点をすべて平行移動させたとき、n個の点のうちのいずれかに該当するのかを確認
        bool flg = true;
        rep(j, 0, m){
            if(S.find(make_pair(mx[j]+x, my[j]+y)) == S.end()) flg=false;
        }
        if(flg){
            cout << x << " " << y << endl;
            break;
        }
    }

    return 0;
}