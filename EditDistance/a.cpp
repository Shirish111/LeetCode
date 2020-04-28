// Edit Distance

// Given two words word1 and word2, find the minimum number of operations
// required to convert word1 to word2.

// You have the following 3 operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// Tags: dynamic_programming

#include <bits/stdc++.h>
using namespace std;

// DP TopDown
class SolutionDPTD {
 public:
  int minDistance(string &w1, string &w2) {
    int m = w1.length(), n = w2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return minDistance(dp, w1, w2, m, n);
  }
  int minDistance(vector<vector<int>> &dp, string &w1, string &w2, int m,
                  int n) {
    if (dp[m][n] != -1) {
      return dp[m][n];
    }
    if (m == 0) {
      dp[m][n] = n;
    } else if (n == 0) {
      dp[m][n] = m;
    } else if (w1[m - 1] == w2[n - 1]) {
      dp[m][n] = minDistance(dp, w1, w2, m - 1, n - 1);
    } else {
      dp[m][n] =
          1 + min(minDistance(dp, w1, w2, m - 1, n),            // Delete char
                  min(minDistance(dp, w1, w2, m, n - 1),        // Insert char
                      minDistance(dp, w1, w2, m - 1, n - 1)));  // Replace char
    }
    return dp[m][n];
  }
};
// DP BottomUp
class SolutionDPBU {
 public:
  int minDistance(string &w1, string &w2) {
    int m = w1.length(), n = w2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i < n + 1; i++) {
      dp[0][i] = i;
    }
    for (int i = 0; i < m + 1; i++) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (w1[i - 1] == w2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
      }
    }
    return dp[m][n];
  }
};
// DP BottomUp Optimized Space
class SolutionDPBUOptimized {
 public:
  int minDistance(string &w1, string &w2) {
    int m = w1.length(), n = w2.length();
    vector<int> dp(n + 1);
    for (int i = 0; i < n + 1; i++) {
      dp[i] = i;
    }
    int prev, temp;
    for (int i = 1; i <= m; i++) {
      prev = i - 1;  // dp[i - 1][j - 1]
      dp[0] = i;     // dp[i][j - 1]
      for (int j = 1; j <= n; j++) {
        temp = dp[j];
        if (w1[i - 1] == w2[j - 1]) {
          dp[j] = prev;
        } else {
          dp[j] = 1 + min(prev, min(dp[j], dp[j - 1]));
        }
        prev = temp;
      }
    }
    return dp[n];
  }
};
void solve() {
  vector<pair<string, string>> tc = {{"horse", "ros"},
                                     {"intention", "execution"}};
  SolutionDPBUOptimized s;
  for (auto &i : tc) {
    cout << i.first << " " << i.second << " = "
         << s.minDistance(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
