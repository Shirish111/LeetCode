// Palindrome Partitioning II

// Given a string s, partition s such that every substring of the partition is a
// palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// Example:

// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
// cut.

// Tags: dynamic_programming, palindrome

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCut(string s) {
    int n = s.length();
    if (n == 0) {
      return 0;
    }
    vector<int> dp(n + 1);
    iota(dp.begin(), dp.end(), -1);
    copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    int left, right;
    for (int center = 1; center <= n; center++) {
      left = right = center;  // Odd Length Palindromes
      while (left > 0 && right <= n) {
        if (s[left - 1] != s[right - 1]) {
          break;
        }
        dp[right] = min(dp[right], 1 + dp[left - 1]);
        right++;
        left--;
      }
      right = center + 1;  // Even Length Palindromes
      left = center;
      while (left > 0 && right <= n) {
        if (s[left - 1] != s[right - 1]) {
          break;
        }
        dp[right] = min(dp[right], 1 + dp[left - 1]);
        right++;
        left--;
      }
    }
    return dp[n];
  }
};
void solve() {
  vector<string> tc = {"aab", "aba", "baacd"};
  Solution s;
  for (auto &i : tc) {
    cout << s.minCut(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
