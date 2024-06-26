// 全探索003
// https://atcoder.jp/contests/abc122/tasks/abc122_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

bool solve (string s, int x, int y){
    vector<char> search = {'A', 'T', 'G', 'C'};
    s = s.substr(x, y);
    rep(i, 0, s.size()){
        bool flg=false;
        rep(j, 0, 4){
            if(s[i]==search[j]) flg = true;
        }
        if(flg == false) return false;
    }
    return true;
}

int main(void) {
    string s;
    cin >> s;

    int ans=0;
    rep(i, 0, s.size()){
        rep(j, 1, s.size()-i+1){
            if(solve(s, i, j)){
                ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
}