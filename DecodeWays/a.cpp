// Decode Ways

// A message containing letters from A-Z is being encoded to numbers using the
// following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number
// of ways to decode it.

// Example 1:

// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
// 6).
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

// Recursive Approach With Memoization
class SolutionTD {
 public:
  vector<int> dp;
  int n;
  int numDecodings(string s) {
    if (s == "") return 0;
    n = s.length();
    dp.assign(n + 1, -1);
    dp[n] = 1;
    return numDecodings(s, 0);
  }
  int numDecodings(string &s, int k) {
    if (dp[k] != -1) {
      return dp[k];
    }
    if (s[k] == '0') {
      dp[k] = 0;
      return dp[k];
    }
    dp[k] = numDecodings(s, k + 1);
    if (k < n - 1 && (s[k] < '2' || (s[k] == '2' && s[k + 1] <= '6'))) {
      dp[k] += numDecodings(s, k + 2);
    }
    return dp[k];
  }
};
// Bottup Up DP
class Solution {
 public:
  int numDecodings(string s) {
    int n = s.length();
    if (n == 0) {
      return 0;
    }
    if (s[0] == '0') {
      return 0;
    }
    vector<int> dp(n + 1);
    dp[n] = 1;
    if (s[n - 1] != '0') {
      dp[n - 1] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == '0') {
        dp[i] = 0;
      } else {
        dp[i] = dp[i + 1];
        if (valid(s, i, n)) {
          dp[i] += dp[i + 2];
        }
      }
    }
    return dp[0];
  }
  bool valid(string &s, int i, int n) {
    if (s[i] == '0') {
      return false;
    }
    if (i == n - 1) {
      return false;
    }
    if (s[i] < '2' || (s[i] == '2' && s[i + 1] <= '6')) {
      return true;
    }
    return false;
  }
};
void solve() {
  vector<string> tc = {"12", "226", "110", "2263", "2222", "227", "202"};
  SolutionTD s;
  for (auto &i : tc) {
    cout << i << " " << s.numDecodings(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
