// Perfect Squares

// Given a positive integer n, find the least number of perfect square numbers
// (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
// Tags: dynamic_programming, interview
// Difficulty: Medium
#include <bits/stdc++.h>
using namespace std;

// dp[0] = 0
// dp[1] = dp[0]+1 = 1
// dp[2] = dp[1]+1 = 2
// dp[3] = dp[2]+1 = 3
// dp[4] = Min{ dp[4-1*1]+1, dp[4-2*2]+1 }
//       = Min{ dp[3]+1, dp[0]+1 }
//       = 1
// dp[5] = Min{ dp[5-1*1]+1, dp[5-2*2]+1 }
//       = Min{ dp[4]+1, dp[1]+1 }
//       = 2
// 						.
// 						.
// 						.
// dp[13] = Min{ dp[13-1*1]+1, dp[13-2*2]+1, dp[13-3*3]+1 }
//        = Min{ dp[12]+1, dp[9]+1, dp[4]+1 }
//        = 2
// 						.
// 						.
// 						.
// dp[n] = Min{ dp[n - i*i] + 1 },  n - i*i >=0 && i >= 1

class Solution {
 public:
  int numSquares(int n) {
    if (n <= 0) {
      return 0;
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

void solve() {
  vector<int> tc = {12, 13};
  Solution s;
  for (auto &i : tc) {
    cout << s.numSquares(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
