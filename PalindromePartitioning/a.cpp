// Palindrome Partitioning

// Given a string s, partition s such that every substring of the partition is a
// palindrome.

// Return all possible palindrome partitioning of s.

// Example:

// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

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
  vector<vector<string>> partition(string s) {
    int n = s.length();
    vector<vector<string>> ans;
    dp.resize(n, vector<int>(n, -1));
    if (n == 0) {
      return ans;
    }
    vector<string> sol;
    d(ans, s, n, sol, 0);
    return ans;
  }
  void d(vector<vector<string>> &ans, string &s, int n, vector<string> &sol,
         int beg) {
    for (int i = beg; i < n; i++) {
      f(ans, s, n, sol, beg, i);
    }
  }
  void f(vector<vector<string>> &ans, string &s, int n, vector<string> &sol,
         int beg, int end) {
    if (isPalin(s, beg, end)) {
      sol.push_back(s.substr(beg, end - beg + 1));
      if (end == n - 1) {
        ans.push_back(sol);
      } else {
        d(ans, s, n, sol, end + 1);
      }
      sol.pop_back();
    }
  }
  bool isPalin(string &s, int beg, int end) {
    if (dp[beg][end] != -1) {
      return dp[beg][end];
    }
    while (beg < end) {
      if (s[beg] != s[end]) {
        dp[beg][end] = 0;
        return false;
      }
      beg++;
      end--;
    }
    dp[beg][end] = 1;
    return true;
  }
};
void solve() {
  vector<string> tc = {"aab", "aba", "aa"};
  Solution s;
  for (auto &i : tc) {
    vector<vector<string>> ans = s.partition(i);
    for (auto &j : ans) {
      copy(j.begin(), j.end(), ostream_iterator<string>(cout, " "));
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
