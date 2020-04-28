//  Regular Expression Matching

//  Given an input string (s) and a pattern (p), implement regular expression
//  matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like
// . or *. Example 1:

// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input:
// s = "aa"
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore,
// by repeating 'a' once, it becomes "aa". Example 3:

// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Example 4:

// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
// it matches "aab". Example 5:

// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false

// Tags: regex, recursion, miscellaneous

#include <bits/stdc++.h>
using namespace std;
// Top Down
class Solution1 {
 public:
  int sl, pl;
  string s, p;
  vector<vector<short>> memo;
  bool isMatch(string s1, string p1) {
    s = s1;
    p = p1;
    sl = s.length();
    pl = p.length();
    memo.resize(sl + 1, vector<short>(pl + 1, -1));
    return f(0, 0);
  }
  bool f(int si, int pi) {
    if (memo[si][pi] != -1) {
      return memo[si][pi];
    }
    if (pi == pl) {
      memo[si][pi] = si == sl;
      return memo[si][pi];
    }
    bool fm = (si < sl) && (s[si] == p[pi] || p[pi] == '.');
    if (pi + 1 < pl && p[pi + 1] == '*') {
      memo[si][pi] = (fm && f(si + 1, pi)) || f(si, pi + 2);
    } else {
      memo[si][pi] = fm && f(si + 1, pi + 1);
    }
    return memo[si][pi];
  }
};
// Bottom Up
class Solution {
 public:
  bool isMatch(string s, string p) {
    int sl = s.length(), pl = p.length();
    vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));
    dp[sl][pl] = true;
    for (int i = sl; i >= 0; i--) {
      for (int j = pl - 1; j >= 0; j--) {
        bool m = (i < sl) && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < pl && p[j + 1] == '*') {
          dp[i][j] = (m && dp[i + 1][j]) || dp[i][j + 2];
        } else {
          dp[i][j] = m && dp[i + 1][j + 1];
        }
      }
    }
    return dp[0][0];
  }
};
void solve() {
  Solution solution;
  string s = "abbabc";
  string p = "ab*.*";
  cout << boolalpha << solution.isMatch(s, p) << "\n";
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
