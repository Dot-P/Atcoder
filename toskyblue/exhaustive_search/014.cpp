// 全探索014
// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
// 発想はあっているが、実装が正しくない

#include <bits/stdc++.h>
using namespace std;
#define rep(i, x, n) for (int i=x; i<n; i++)
using LL = long long int;
using VI = vector<int>;
using VVI = vector<VI>;

int main(void) {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    rep(i, 0, n) cin >> a[i];

    LL ans = 1e11;
    rep(mask, 0, (1 << n)){

        int c = bitset<32>(mask).count();
        if(c != k) continue;

        bool flg = true;
        LL left_max = 0;
        vector<LL> building;
        rep(i, 0, n){
            if(mask & (1 << i)){
                building.push_back(a[i]);
                flg = false;
            }
            if(flg) left_max = max(left_max, a[i]);
        }
        if(left_max >= building[0]) continue;
        LL total = 0;
        rep(i, 0, building.size()-1){
            total += max(building[i]+1-building[i+1], 0LL);
            building[i+1] = max(building[i]+1, building[i+1]);
        }
        ans = min(ans, total);
    }

    cout << ans << endl;
}


// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, x, n) for (int i = x; i < n; i++)
// using LL = long long int;
// using VI = vector<int>;
// using VVI = vector<VI>;

// int main() {
//     LL n, k;
//     cin >> n >> k;
//     vector<LL> a(n);
//     rep(i, 0, n) cin >> a[i];

//     LL ans = LLONG_MAX;

//     // 全てのビットマスクを試す
//     rep(mask, 0, (1 << n)) {
//         // maskで選ばれた建物の数をカウント
//         int c = bitset<32>(mask).count();
//         if (c < k) continue; // K個以上の建物が選ばれていない場合は無視

//         LL total = 0;
//         LL left_max = 0;
//         vector<LL> height = a; // 建物の高さをコピー

//         // ビットマスクを適用して建物の高さを調整
//         rep(i, 0, n) {
//             if (mask & (1 << i)) { // i番目の建物が見えるように選択された場合
//                 if (height[i] <= left_max) {
//                     total += left_max + 1 - height[i];
//                     height[i] = left_max + 1; // 高さを調整
//                 }
//             }
//             left_max = max(left_max, height[i]); // 左から見たときの最大の高さを更新
//         }

//         ans = min(ans, total); // 最小のコストを更新
//     }

//     cout << ans << endl;
//     return 0;
// }
