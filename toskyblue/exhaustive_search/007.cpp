// 全探査007
// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int n;
VI x(4000), y(4000);

bool square (int a, int b){
    int diffx = x[b]-x[a];
    int diffy = y[b]-y[a];

    bool flg1=false, flg2=false, flg3=false, flg4=false;

    rep(i, 0, n){
        if(x[i]==y[a]+diffx and y[i]==x[a]-diffy) flg1 = true;
        if(x[i]==y[b]+diffx and y[i]==x[b]-diffy) flg2 = true;
        if(x[i]==y[a]-diffx and y[i]==x[a]+diffy) flg3 = true;
        if(x[i]==y[b]-diffx and y[i]==x[b]+diffy) flg4 = true;
        
    }

    return (flg1 and flg2) or (flg3 and flg4);
}

int main(void) {
    cin >> n;
    rep(i, 0, n) cin >> x[i] >> y[i];

    int ans = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            // 選ばれた二点が正方形を作るかどうかを考える
            if(square(i, j)) ans = max(ans, (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
    }
    cout << ans << endl;
}