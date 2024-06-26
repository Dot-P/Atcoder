// 全探査006
// https://atcoder.jp/contests/abc095/tasks/arc096_a

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, x, n) for (int i=x; i<n; i++)
// using LL = long long int;
// using VI = vector<int>;
// using VVI = vector<VI>;

// int main(void) {
//     int a, b, c, x, y;
//     cin >> a >> b >> c >> x >> y;

//     int many = 0;
//     if(x == y) many = 0;
//     else if(x > y) many = a;
//     else many = b;

//     cout << min({a*x+b*y, min(x, y)*2*c + many * abs(x-y), 2*c*max(x, y)}) << endl;
// }

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1e9;
    for(int i=0; i<=max(x, y)*2; i+=2){
        int cost = a * max(0, x - i/2) + b * max(0, y - i/2) + c * i;
        ans = min(ans, cost);
    }
    cout << ans << endl;
}