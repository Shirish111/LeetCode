// Minimum Path Sum

// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example:

// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

// Tags: binary_tree, recursion

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& a) {
    int m = a.size();
    if (m == 0) {
      return 0;
    }
    int n = a[0].size();
    if (n == 0) {
      return 0;
    }
    for (int i = 1; i < m; i++) {
      a[i][0] += a[i - 1][0];
    }
    for (int i = 1; i < n; i++) {
      a[0][i] += a[0][i - 1];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        a[i][j] += min(a[i - 1][j], a[i][j - 1]);
      }
    }
    return a[m - 1][n - 1];
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.minPathSum(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
