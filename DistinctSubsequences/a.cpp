// Distinct Subsequences

// Given a string S and a string T, count the number of distinct subsequences of
// S which equals T.

// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).

// Example 1:

// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:

// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)

// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// Example 2:

// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:

// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)

// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

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
  vector<vector<int>> dp;
  int numDistinct(string s, string t) {
    int m = s.length(), n = t.length();
    dp.assign(m, vector<int>(n, -1));
    return numDistinct(s, t, m - 1, n - 1);
  }
  int numDistinct(string &s, string &t, int m, int n) {
    if (n < 0) {
      return 1;
    }
    if (m < 0) {
      return 0;
    }
    if (dp[m][n] != -1) {
      return dp[m][n];
    }
    if (s[m] == t[n]) {
      dp[m][n] = numDistinct(s, t, m - 1, n - 1) + numDistinct(s, t, m - 1, n);
    } else {
      dp[m][n] = numDistinct(s, t, m - 1, n);
    }
    return dp[m][n];
  }
};
void solve() {
  vector<pair<string, string>> tc = {{"rabbbit", "rabbit"}};
  Solution s;
  for (auto &i : tc) {
    cout << s.numDistinct(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
