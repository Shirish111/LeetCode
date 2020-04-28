// Wildcard Matching

// Given an input string (s) and a pattern (p), implement wildcard pattern
// matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Note:

// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like
// ? or *. Example 1:

// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not
// match 'b'. Example 4:

// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*'
// matches the substring "dce". Example 5:

// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false

// Tags: recursion, regex, miscellaneous

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int sl, pl;
  bool isMatch(string &s, string &p) {
    sl = s.length(), pl = p.length();
    vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));
    return isMatch(memo, s, p, 0, 0);
  }
  bool isMatch(vector<vector<int>> &memo, string &s, string &p, int si,
               int pi) {
    if (memo[si][pi] != -1) {
      return memo[si][pi];
    }
    if (pi == pl) {
      return si == sl;
    }
    if (p[pi] == '*') {
      memo[si][pi] = isMatch(memo, s, p, si, pi + 1) ||
                     (si < sl && isMatch(memo, s, p, si + 1, pi));
    } else {
      bool fm = (si < sl) && (s[si] == p[pi] || p[pi] == '?');
      memo[si][pi] = fm && isMatch(memo, s, p, si + 1, pi + 1);
    }
    return memo[si][pi];
  }
};
void solve() {
  vector<pair<string, string>> tc = {
      {"aa", "*"},
      {"", "*"},
      {"cb", "?a"},
      {"adceb", "*a*b"},
      {"acdcb", "a*c?b"},
      {"aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"}};
  vector<bool> expected = {true, true, false, true, false, false};
  Solution s;
  for (int i = 0; i < tc.size(); i++) {
    bool ans = s.isMatch(tc[i].first, tc[i].second);
    if (ans == expected[i]) {
      cout << "PASSED: ";
    } else {
      cout << "FAILED: ";
    }
    cout << boolalpha << ans << " " << tc[i].first << " " << tc[i].second
         << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
