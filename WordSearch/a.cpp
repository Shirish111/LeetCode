// Word Search

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where
// "adjacent" cells are those horizontally or vertically neighboring. The same
// letter cell may not be used more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define PB push_back
#define F0(I, N) for (ll I = 0; I < N; I++)
#define F1(I, N) for (ll I = 1; I <= N; I++)
#define F(I, X, N) for (ll I = X; I < N; I++)
#define R0(I, N) for (ll I = N - 1; I >= 0; I--)
#define R1(I, N) for (ll I = N; I > 0; I--)
#define R(I, X, N) for (ll I = N - 1; I >= X; I--)
#define A(X) X.begin(), X.end()

class Solution {
 public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  bool exist(vector<vector<char>> &a, string w) {
    int m = a.size(), l = w.length();
    if (m == 0) {
      return l == 0;
    }
    int n = a[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (exist(a, w, visited, m, n, i, j, l, 0)) {
          return true;
        }
      }
    }
    return false;
  }
  bool exist(vector<vector<char>> &a, string &w, vector<vector<bool>> &visited,
             int m, int n, int i, int j, int l, int k) {
    if (k == l) {
      return true;
    }
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
        a[i][j] != w[k]) {
      return false;
    }
    visited[i][j] = true;
    for (int p = 0; p < 4; p++) {
      if (exist(a, w, visited, m, n, i + dx[p], j + dy[p], l, k + 1)) {
        return true;
      }
    }
    visited[i][j] = false;
    return false;
  }
};
void solve() {
  vector<pair<vector<vector<char>>, string>> tc = {
      {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
       "ABCCED"},
      {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
       "SEE"},
      {{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
       "ABCB"}};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.exist(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
