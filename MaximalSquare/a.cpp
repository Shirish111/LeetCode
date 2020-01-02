// Maximal Square

// Given a 2D binary matrix filled with 0's and 1's, find the largest square
// containing only 1's and return its area.

// Example:

// Input:

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4

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

// Brute Force
class SolutionBF {
 public:
  int maximalSquare(vector<vector<char>>& a) {
    int m = a.size();
    if (m == 0) {
      return 0;
    }
    int n = a[0].size();
    int mx = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == '1') {
          int cx = 1;
          bool flag = true;
          int x, y;
          x = i + 1;
          y = j + 1;
          while (x < m && y < n) {
            for (int k = i; k <= x; ++k) {
              if (a[k][y] == '0') {
                flag = false;
                break;
              }
            }
            if (flag == false) {
              break;
            }
            for (int k = j; k <= y; ++k) {
              if (a[x][k] == '0') {
                flag = false;
                break;
              }
            }
            if (flag == false) {
              break;
            }
            cx++;
            x += 1;
            y += 1;
          }
          mx = max(mx, cx);
        }
      }
    }
    return mx * mx;
  }
};
// DP
class SolutionDP {
 public:
  int maximalSquare(vector<vector<char>>& a) {
    int m = a.size();
    if (m == 0) {
      return 0;
    }
    int n = a[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    int mx = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i - 1][j - 1] == '1') {
          dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
          mx = max(mx, dp[i][j]);
        }
      }
    }
    return mx * mx;
  }
};
// Space optimised DP
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& a) {
    int m = a.size();
    if (m == 0) {
      return 0;
    }
    int n = a[0].size();
    vector<vector<int>> dp(2, vector<int>(n + 1));
    int mx = 0;
    int cur = 1, prev = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i - 1][j - 1] == '1') {
          dp[cur][j] =
              min(dp[prev][j], min(dp[prev][j - 1], dp[cur][j - 1])) + 1;
          mx = max(mx, dp[cur][j]);
        } else {
          dp[cur][j] = 0;
        }
      }
      cur = !cur;
      prev = !prev;
    }
    return mx * mx;
  }
};
void solve() {
  vector<vector<vector<char>>> tc = {
      {{'1', '0', '1', '0', '0'},
       {'1', '0', '1', '1', '1'},
       {'1', '1', '1', '1', '1'},
       {'1', '0', '0', '1', '0'}},
      {{{'1', '1'}, {'1', '1'}}},
      {{'1', '1', '1', '1', '1', '1', '1', '1'},
       {'1', '1', '1', '1', '1', '1', '1', '0'},
       {'1', '1', '1', '1', '1', '1', '1', '0'},
       {'1', '1', '1', '1', '1', '0', '0', '0'},
       {'0', '1', '1', '1', '1', '0', '0', '0'}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.maximalSquare(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
