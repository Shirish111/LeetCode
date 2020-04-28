// Spiral Matrix

// Given a matrix of m x n elements (m rows, n columns), return all elements of
// the matrix in spiral order.

// Example 1:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// Tags: matrices, spiral, hashing, miscellaneous

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
 public:
  vector<int> spiralOrder(vector<vector<int>>& a) {
    vector<int> ans;
    int m = a.size();
    if (m == 0) {
      return ans;
    }
    int n = a[0].size();
    vector<vector<bool>> seen(m, vector<bool>(n, false));
    int r = 0, c = 0, rr, cc;
    int di = 0;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    for (int i = 0; i < n * m; i++) {
      ans.push_back(a[r][c]);
      seen[r][c] = true;
      rr = r + dr[di];
      cc = c + dc[di];
      if (rr >= 0 && rr < m && cc >= 0 && cc < n && !seen[rr][cc]) {
        r = rr;
        c = cc;
      } else {
        di = (di + 1) % 4;
        r += dr[di];
        c += dc[di];
      }
    }
    return ans;
  }
};
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& a) {
    vector<int> ans;
    int m = a.size();
    if (m == 0) {
      return ans;
    }
    int n = a[0].size();
    if (n == 0) {
      return ans;
    }
    int cmin = 0, cmax = n - 1, rmin = 0, rmax = m - 1;
    while (cmin <= cmax && rmin <= rmax) {
      for (int i = cmin; i <= cmax; i++) {
        ans.push_back(a[rmin][i]);
      }
      for (int i = rmin + 1; i <= rmax; i++) {
        ans.push_back(a[i][cmax]);
      }
      if (rmax > rmin) {
        for (int i = cmax - 1; i >= cmin; i--) {
          ans.push_back(a[rmax][i]);
        }
      }
      if (cmax > cmin) {
        for (int i = rmax - 1; i > rmin; i--) {
          ans.push_back(a[i][cmin]);
        }
      }
      cmin++;
      cmax--;
      rmin++;
      rmax--;
    }
    return ans;
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      {{1}},
      {{1, 2, 3, 4, 5},
       {6, 7, 8, 9, 10},
       {11, 12, 13, 14, 15},
       {16, 17, 18, 19, 20},
       {21, 22, 23, 24, 25}},
      {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}},
      {}};
  Solution s;
  for (auto& i : tc) {
    vector<int> a = s.spiralOrder(i);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
