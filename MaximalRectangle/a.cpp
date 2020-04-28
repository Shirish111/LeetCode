// Maximal Rectangle

// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing only 1's and return its area.

// Example:

// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6

// Tags: miscellaneous, dynamic_programming, two_sweeps

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& a) {
    int m = a.size();
    if (m == 0) {
      return 0;
    }
    int n = a[0].size();
    if (n == 0) {
      return 0;
    }
    vector<int> h(n, 0), left(n, -1), right(n, n);
    int mx = 0;
    for (int i = 0; i < m; i++) {
      // Heights
      for (int j = 0; j < n; j++) {
        h[j] = a[i][j] == '0' ? 0 : h[j] + 1;
      }
      // Left
      int cur_left = -1;
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '0') {
          left[j] = -1;
          cur_left = j;
        } else {
          left[j] = max(left[j], cur_left);
        }
      }
      // Right
      int cur_right = n;
      for (int j = n - 1; j >= 0; j--) {
        if (a[i][j] == '0') {
          right[j] = n;
          cur_right = j;
        } else {
          right[j] = min(right[j], cur_right);
        }
      }
      // Max Area
      for (int j = 0; j < n; j++) {
        mx = max(mx, h[j] * (right[j] - left[j] - 1));
      }
    }
    return mx;
  }
};
void solve() {
  vector<vector<vector<char>>> tc = {{{'1', '0', '1', '0', '0'},
                                      {'1', '0', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '0', '0', '1', '0'}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.maximalRectangle(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
