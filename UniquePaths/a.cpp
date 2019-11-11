// Unique Paths

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).

// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).

// How many possible unique paths are there?

// Above is a 7 x 3 grid. How many possible unique paths are there?

// Note: m and n will be at most 100.

// Example 1:

// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the
// bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right
// Example 2:

// Input: m = 7, n = 3
// Output: 28

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

class Solution1 {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) {
      return 0;
    }
    if (m < n) {
      swap(m, n);
    }
    unsigned long long p = 1;
    unsigned long long np = 1;
    for (unsigned long long i = m + n - 2; i >= m; --i) {
      p = i * p;
    }
    for (unsigned long long i = 2; i < n; ++i) {
      np = i * np;
    }
    return p / np;
  }
};
class Solution {
 public:
  // Using DP
  int uniquePaths(int m, int n) {
    vector<vector<long long>> mat(m, vector<long long>(n));
    if (m == 0 || n == 0) {
      return 0;
    }
    for (int i = 0; i < n; i++) {
      mat[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
      mat[i][0] = 1;
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
      }
    }
    return mat[m - 1][n - 1];
  }
};
void solve() {
  vector<pair<int, int>> tc = {{3, 2}, {7, 3}, {23, 12}, {1, 2}};
  Solution s;
  for (auto &i : tc) {
    cout << s.uniquePaths(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
