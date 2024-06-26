// 全探索006
// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

bool search(string s, int x, int y, int z){
    bool flg1 = false;
    bool flg2 = false;
    rep(i, 0, s.size()){
        if(flg2 and flg1 and s[i]-'0'==z){
            //cout << x << y << z << endl;
            return true;
        }
        if(flg1 and s[i]-'0'==y){
            flg2 = true;
        }
        if(s[i]-'0'==x){
            flg1 = true;
        }
    }
    return false;
}

int main(void) {
    int n;
    string s;
    cin >> n >> s;

    int cnt=0;
    rep(i, 0, 10){
        rep(j, 0, 10){
            rep(k, 0, 10){
                if(search(s, i, j, k)) cnt++;
            }
        }
    }

    cout << cnt << endl;
}