// Set Matrix Zeroes

// Given a m x n matrix, if an element is 0, set its entire row and column to 0.
// Do it in-place.

// Example 1:

// Input:
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output:
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:

// Input:
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output:
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// Follow up:

// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

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

// Using O(mn)
class SolutionMN {
 public:
  void setZeroes(vector<vector<int>>& a) {
    int m = a.size();
    if (m == 0) {
      return;
    }
    int n = a[0].size();
    vector<vector<int>> cp(a);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (cp[i][j] == 0) {
          for (int k = 0; k < n; k++) {
            a[i][k] = 0;
          }
          for (int k = 0; k < m; k++) {
            a[k][j] = 0;
          }
        }
      }
    }
  }
};
// Using O(m + n) space
class SolutionMplusN {
 public:
  void setZeroes(vector<vector<int>>& a) {
    int m = a.size();
    if (m == 0) {
      return;
    }
    int n = a[0].size();
    vector<bool> row(m, false), col(n, false);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 0) {
          row[i] = true;
          col[j] = true;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      if (row[i]) {
        for (int j = 0; j < n; j++) {
          a[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (col[i]) {
        for (int j = 0; j < m; j++) {
          a[j][i] = 0;
        }
      }
    }
  }
};
// Using Constant Space
// Store states of row in a[row][0], and that of col in a[0][col]
// Knowing whether col[0] should be all zeroes is stored in col0 variable
// a[0][0] used to store whether row 0 should be zero
// col0 used to store whether col 0 should be zero
class Solution {
 public:
  void setZeroes(vector<vector<int>>& a) {
    int m = a.size(), col0 = 1;
    if (m == 0) {
      return;
    }
    int n = a[0].size();
    for (int i = 0; i < m; i++) {
      if (a[i][0] == 0) {
        col0 = 0;
      }
      for (int j = 1; j < n; j++) {
        if (a[i][j] == 0) {
          a[i][0] = a[0][j] = 0;
        }
      }
    }
    // Bottom Up filling
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 1; j--) {  // Except the zeroth column
        if (a[i][0] == 0 || a[0][j] == 0) {
          a[i][j] = 0;
        }
      }
      if (col0 ==
          0) {  // Since zeroth column depends on col0 and not on a[0][0]
        a[i][0] = 0;
      }
    }
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
                                    {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
                                    {{1, 1, 1}, {0, 1, 2}}};
  SolutionMplusN s;
  for (auto& i : tc) {
    s.setZeroes(i);
    for (auto& j : i) {
      copy(j.begin(), j.end(), ostream_iterator<int>(cout, " "));
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
