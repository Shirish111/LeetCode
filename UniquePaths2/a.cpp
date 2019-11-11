// Unique Paths II

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).

// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths
// would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Note: m and n will be at most 100.

// Example 1:

// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

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
  // Using DP
  int uniquePathsWithObstacles(vector<vector<int>>& a) {
    int m = a.size();
    if (m == 0) {
      return 0;
    }
    int n = a[0].size();
    if (n == 0 || a[0][0]) {
      return 0;
    }
    a[0][0] = !a[0][0];
    for (int i = 1; i < m; i++) {
      a[i][0] = a[i - 1][0] & !a[i][0];
    }
    for (int i = 1; i < n; i++) {
      a[0][i] = a[0][i - 1] & !a[0][i];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (a[i][j] == 1) {
          a[i][j] = 0;
        } else {
          a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
      }
    }
    return a[m - 1][n - 1];
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {
      {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, {{{0, 0}}}, {{{1, 0}}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.uniquePathsWithObstacles(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
