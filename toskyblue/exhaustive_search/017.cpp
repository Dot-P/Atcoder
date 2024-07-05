// 全探索017
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=ja
// 対角線上を成分の差と和で表現するのはコツかも

#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, n) for (int i=x; i<n; i++)
using VI = vector<int>;

int main() {
    int k;
    cin >> k;
    
    VI h(k), w(k);
    rep(i, 0, k) cin >> h[i] >> w[i];

    vector<vector<char>> board(8, vector<char>(8, '.'));

    // クイーンを初期配置
    rep(i, 0, k) board[h[i]][w[i]] = 'Q';

    // 他のクイーンとの衝突を避けるために使用可能な行と列を追跡
    VI ignore_rows, ignore_cols;
    vector<bool> rows_used(8, false), cols_used(8, false);

    // すでにクイーンが置かれている行と列をマーク
    rep(i, 0, k) {
        rows_used[h[i]] = true;
        cols_used[w[i]] = true;
    }

    // 使用されていない行と列を記録
    rep(i, 0, 8) {
        if (!rows_used[i]) ignore_rows.push_back(i);
        if (!cols_used[i]) ignore_cols.push_back(i);
    }

    // 対角線の使用状況を追跡
    vector<bool> diag1(15, false), diag2(15, false);

    // 既に置かれているクイーンに基づいて対角線をマーク
    rep(i, 0, k) {
        diag1[h[i] - w[i] + 7] = true;
        diag2[h[i] + w[i]] = true;
    }

    VI ans;
    do {
        bool valid = true;
        vector<bool> temp_diag1 = diag1, temp_diag2 = diag2;

        rep(i, 0, ignore_rows.size()) {
            int row = ignore_rows[i], col = ignore_cols[i];
            if (temp_diag1[row - col + 7] || temp_diag2[row + col]) {
                valid = false;
                break;
            }
            temp_diag1[row - col + 7] = true;
            temp_diag2[row + col] = true;
        }
        if (!valid) continue;
        ans = ignore_rows;
        break;
    } while (next_permutation(ignore_rows.begin(), ignore_rows.end()));

    // 解をボードに反映
    if (!ans.empty()) {
        rep(i, 0, ans.size()) board[ans[i]][ignore_cols[i]] = 'Q';
    }

    // ボードの表示
    rep(i, 0, 8) {
        rep(j, 0, 8) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
