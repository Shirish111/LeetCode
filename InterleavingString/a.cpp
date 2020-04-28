// Interleaving String

// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// Example 1:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

// Tags: dynamic_programming

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int n1, n2, n3;
  vector<vector<int>> dp;
  bool isInterleave(string& s1, string& s2, string& s3) {
    n1 = s1.length();
    n2 = s2.length();
    n3 = s3.length();
    if (n1 + n2 != n3) {
      return false;
    }
    dp.assign(n1 + 1, vector<int>(n2 + 1, -1));
    return isInterleave(s1, s2, s3, 0, 0, 0);
  }
  bool isInterleave(string& s1, string& s2, string& s3, int i, int j, int k) {
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    if (k == n3) {
      return i == n1 && j == n2;
    }
    if (i < n1 && s1[i] == s3[k]) {
      if (isInterleave(s1, s2, s3, i + 1, j, k + 1)) {
        return true;
      }
    }
    if (j < n2 && s2[j] == s3[k]) {
      if (isInterleave(s1, s2, s3, i, j + 1, k + 1)) {
        return true;
      }
    }
    dp[i][j] = 0;
    return false;
  }
};
void solve() {
  vector<vector<string>> tc = {{"aabcc", "dbbca", "aadbbcbcac"},
                               {"aabcc", "dbbca", "aadbbbaccc"}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.isInterleave(i[0], i[1], i[2]) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
