// Dungeon Game

// The demons had captured the princess (P) and imprisoned her in the
// bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid
// out in a 2D grid. Our valiant knight (K) was initially positioned in the
// top-left room and must fight his way through the dungeon to rescue the
// princess.

// The knight has an initial health point represented by a positive integer. If
// at any point his health point drops to 0 or below, he dies immediately.

// Some of the rooms are guarded by demons, so the knight loses health (negative
// integers) upon entering these rooms; other rooms are either empty (0's) or
// contain magic orbs that increase the knight's health (positive integers).

// In order to reach the princess as quickly as possible, the knight decides to
// move only rightward or downward in each step.

// Write a function to determine the knight's minimum initial health so that he
// is able to rescue the princess.

// For example, given the dungeon below, the initial health of the knight must
// be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

// -2 (K)	-3	3
// -5	-10	1
// 10	30	-5 (P)

// Note:

// The knight's health has no upper bound.
// Any room can contain threats or power-ups, even the first room the knight
// enters and the bottom-right room where the princess is imprisoned.

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
  int calculateMinimumHP(vector<vector<int>> &a) {
    int m = a.size();
    if (m == 0) {
      return 1;
    }
    int n = a[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[m][n - 1] = dp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int need = min(dp[i + 1][j], dp[i][j + 1]) - a[i][j];
        dp[i][j] = need <= 0 ? 1 : need;
      }
    }
    return dp[0][0];
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}};
  Solution s;
  for (auto &i : tc) {
    cout << s.calculateMinimumHP(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
