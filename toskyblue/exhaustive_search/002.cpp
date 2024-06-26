// 全探索2
// https://atcoder.jp/contests/abc106/tasks/abc106_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

bool solve (int x){
    int cnt=1;
    rep(i, 3, x+1){
        if(x%i==0) cnt++;
    }
    if(cnt == 8) return true;
    return false;
}

int main(void) {
    int N;
    cin >> N;
    int cnt=0;
    rep(i, 1, N+1){
        if(i%2==0) continue;
        if(solve(i)) cnt++; 
    }
    cout << cnt << endl;
}