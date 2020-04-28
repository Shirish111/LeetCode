// Number of Islands

// Given a 2d grid map of '1's (land) and '0's (water), count the number of
// islands. An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically. You may assume all four edges of
// the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

// Tags: ufds, dfs, recursion, graph

#include <bits/stdc++.h>
using namespace std;

// TODO UFDS
class Solution {
 public:
  int m, n;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int numIslands(vector<vector<char>> &g) {
    m = g.size();
    if (m == 0) {
      return 0;
    }
    n = g[0].size();
    int cur = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == '1') {
          dfs(g, i, j);
          cur++;
        }
      }
    }
    return cur;
  }
  void dfs(vector<vector<char>> &g, int i, int j) {
    g[i][j] = '2';  // Visited
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k], y = j + dy[k];
      if (x < 0 || x == m || y < 0 || y == n || g[x][y] != '1') {
        continue;
      }
      dfs(g, x, y);
    }
  }
};
void solve() {
  vector<vector<vector<char>>> tc = {{{'1', '1', '1', '1', '0'},
                                      {'1', '1', '0', '1', '0'},
                                      {'1', '1', '0', '0', '0'},
                                      {'0', '0', '0', '0', '0'}},
                                     {{'1', '1', '0', '0', '0'},
                                      {'1', '1', '0', '0', '0'},
                                      {'0', '0', '1', '0', '0'},
                                      {'0', '0', '0', '1', '1'}}};
  Solution s;
  for (auto &i : tc) {
    cout << s.numIslands(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
