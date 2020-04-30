// Maximum Side Length of a Square with Sum Less than or Equal to Threshold

// Given a m x n matrix mat and an integer threshold. Return the maximum
// side-length of a square with a sum less than or equal to threshold or return
// 0 if there is no such square.

// Example 1:

// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
// Output: 2
// Explanation: The maximum side length of square with sum less than 4 is 2 as
// shown. Example 2:

// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]],
// threshold = 1 Output: 0 Example 3:

// Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
// Output: 3
// Example 4:

// Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]],
// threshold = 40184 Output: 2

// Constraints:

// 1 <= m, n <= 300
// m == mat.length
// n == mat[i].length
// 0 <= mat[i][j] <= 10000
// 0 <= threshold <= 10^5
// Tags: binary_search, dynamic_programming, sliding
// Status: Done
// Write: TODO

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  class PrefixSumGrid {
   public:
    vector<vector<int>> dp;
    PrefixSumGrid(vector<vector<int>>& a) {
      int m = a.size();
      int n = a[0].size();
      dp.assign(m + 1, vector<int>(n + 1, 0));
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + a[i][j];
        }
      }
    }
    int query(int x1, int y1, int x2, int y2) {
      if (x1 < 0 || y1 < 0) {
        return dp[x2 + 1][y2 + 1];
      }
      return dp[x2 + 1][y2 + 1] - dp[x1][y2 + 1] - dp[x2 + 1][y1] + dp[x1][y1];
    }
  };
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size();
    if (m == 0) {
      return 0;
    }
    int n = mat[0].size();
    PrefixSumGrid p(mat);
    int mx = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i >= mx && j >= mx && p.query(i - mx, j - mx, i, j) <= threshold) {
          mx++;
        }
      }
    }
    return mx;
  }
};

void solve() {
  vector<pair<vector<vector<int>>, int>> tc = {
      {{{1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}},
       4},
      {{{2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2}},
       1},
      {{{1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}, 6},
      {{{18, 70}, {61, 1}, {25, 85}, {14, 40}, {11, 96}, {97, 96}, {63, 45}},
       40184}};
  Solution s;
  for (auto& i : tc) {
    cout << s.maxSideLength(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
