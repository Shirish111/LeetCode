// Surrounded Regions

// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
// surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded
// region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on
// the border of the board are not flipped to 'X'. Any 'O' that is not on the
// border and it is not connected to an 'O' on the border will be flipped to
// 'X'. Two cells are connected if they are adjacent cells connected
// horizontally or vertically.

// Tags: matrices, graph, ufds, dfs, hashing

#include <bits/stdc++.h>
using namespace std;

// Approach 1
class Solution {
 public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  void solve(vector<vector<char>> &b) {
    int m = b.size();
    if (m == 0) {
      return;
    }
    int n = b[0].size();
    char c;
    vector<pair<int, int>> locations;
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (b[i][j] == 'O') {
          locations.clear();
          if (check(b, i, j, m, n, locations)) {
            c = 'X';
          } else {
            c = 'o';
          }
          for (auto &k : locations) {
            b[k.first][k.second] = c;
          }
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (b[i][j] == 'o') {
          b[i][j] = 'O';
        }
      }
    }
  }
  bool check(vector<vector<char>> &b, int i, int j, int m, int n,
             vector<pair<int, int>> &locations) {
    if (b[i][j] == 'X' || b[i][j] == 'P') {
      return true;
    }
    if (b[i][j] == 'o') {
      return false;
    }
    locations.push_back({i, j});
    if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
      return false;
    }
    bool ans = true;
    b[i][j] = 'P';
    for (int k = 0; k < 4; k++) {
      if (!check(b, i + dx[k], j + dy[k], m, n, locations)) {
        return false;
      }
    }
    return true;
  }
};
// Approach 2
class Solution2 {
 public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  void solve(vector<vector<char>> &b) {
    int m = b.size();
    if (m == 0) {
      return;
    }
    int n = b[0].size();
    vector<pair<int, int>> corners = {{0, 0}, {m - 1, 0}, {0, 0}, {0, n - 1}};
    vector<pair<int, int>> moves = {{0, 1}, {0, 1}, {1, 0}, {1, 0}};
    for (int i = 0; i < 4; i++) {
      fill_array1(b, m, n, corners[i], moves[i]);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (b[i][j] == 'O') {
          b[i][j] = 'X';
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (b[i][j] == 'o') {
          b[i][j] = 'O';
        }
      }
    }
  }
  void fill_array1(vector<vector<char>> &b, int m, int n, pair<int, int> &c,
                   pair<int, int> &move) {
    int x = c.first, y = c.second;
    int len;
    if (move.first == 0) {
      len = n;
    } else {
      len = m;
    }
    while (len--) {
      if (b[x][y] == 'O') {
        fill_with(b, m, n, x, y);
      }
      x += move.first;
      y += move.second;
    }
  }
  void fill_with(vector<vector<char>> &b, int m, int n, int i, int j) {
    if (i < 0 || i == m || j < 0 || j == n) {
      return;
    }
    if (b[i][j] != 'O') {
      return;
    }
    b[i][j] = 'o';
    for (int k = 0; k < 4; k++) {
      fill_with(b, m, n, i + dx[k], j + dy[k]);
    }
  }
};

void solve() {
  vector<vector<vector<char>>> tc = {
      {{'X', 'X', 'X', 'X'},
       {'X', 'O', 'O', 'X'},
       {'X', 'X', 'O', 'X'},
       {'X', 'O', 'X', 'X'}},
      {{'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
       {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
       {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
       {'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
       {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
       {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'O'},
       {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'X', 'O'},
       {'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'X'},
       {'O', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
       {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'}},
      {{'O', 'O', 'O', 'O', 'X', 'X'},
       {'O', 'O', 'O', 'O', 'O', 'O'},
       {'O', 'X', 'O', 'X', 'O', 'O'},
       {'O', 'X', 'O', 'O', 'X', 'O'},
       {'O', 'X', 'O', 'X', 'O', 'O'},
       {'O', 'X', 'O', 'O', 'O', 'O'}}};
  vector<vector<char>> ans = {
      {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O'},
      {'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'X'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X'},
      {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'},
      {'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
      {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O'},
      {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X'},
      {'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O'},
      {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O'}};
  SolutionBFS s;
  for (auto &i : tc) {
    cout << "BF:"
         << "\n";
    for (auto &j : i) {
      copy(j.begin(), j.end(), ostream_iterator<char>(cout, " "));
      cout << "\n";
    }
    cout << "AF:"
         << "\n";
    s.solve(i);
    for (auto &j : i) {
      copy(j.begin(), j.end(), ostream_iterator<char>(cout, " "));
      cout << "\n";
    }
  }
}
int main() {
  // cin.tie(nullptr);
  // ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
