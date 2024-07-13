// 三分法01
// https://atcoder.jp/contests/arc054/tasks/arc054_b
// 凸関数の極値を求めることが可能

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

double P;

double f(double x){
    return x + P * pow(2.0, -x/1.5);
}

int main(void) {
    cin >> P;
    double l = 0, r = P;
    while(r - l > 1e-12){
        double mid1 = l + (r-l)/3;
        double mid2 = l + 2 * (r-l)/3;
        if(f(mid1)<f(mid2)) r = mid2;
        else l = mid1;
    }
    cout << setprecision(10) << f(r) << endl;
}