// Triangle

// Given a triangle, find the minimum path sum from top to bottom. Each step you
// may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:

// Bonus point if you are able to do this using only O(n) extra space, where n
// is the total number of rows in the triangle.

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
  int m, n;
  vector<vector<int>> dp;
  int minimumTotal(vector<vector<int>>& t) {
    m = t.size();
    if (m == 0) {
      return 0;
    }
    n = t[m - 1].size();
    dp.assign(m, vector<int>(n, -1));
    return minimumTotal(t, 0, 0);
  }
  int minimumTotal(vector<vector<int>>& t, int r, int i) {
    if (r == n) {
      return 0;
    }
    if (dp[r][i] != -1) {
      return dp[r][i];
    }
    dp[r][i] =
        t[r][i] + min(minimumTotal(t, r + 1, i), minimumTotal(t, r + 1, i + 1));
    return dp[r][i];
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.minimumTotal(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
