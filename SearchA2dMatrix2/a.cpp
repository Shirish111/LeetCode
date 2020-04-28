// Search a 2D Matrix II

// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// Example:

// Consider the following matrix:

// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.

// Given target = 20, return false.

// Tags: matrices, search

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& a, int t) {
    int m = a.size();
    if (m == 0) {
      return false;
    }
    int n = a[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      if (a[i][j] == t) {
        return true;
      }
      if (t > a[i][j]) {
        i++;
      } else if (t < a[i][j]) {
        j--;
      }
    }
    return false;
  }
};
void solve() {
  vector<pair<vector<vector<int>>, int>> tc = {{{{1, 4, 7, 11, 15},
                                                 {2, 5, 8, 12, 19},
                                                 {3, 6, 9, 16, 22},
                                                 {10, 13, 14, 17, 24},
                                                 {18, 21, 23, 26, 30}},
                                                5}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.searchMatrix(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
