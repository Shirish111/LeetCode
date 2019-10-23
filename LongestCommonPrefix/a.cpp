// Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of
// strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

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
  string longestCommonPrefix(vector<string> &v) {
    if (v.size() == 0) {
      return "";
    }
    return process(v, 0, v.size() - 1);
  }
  string common_string(string &l, string &r) {
    int mn = min(l.length(), r.length());
    int i = 0;
    for (int i = 0; i < mn; i++) {
      if (l[i] != r[i]) {
        return l.substr(0, i);
      }
    }
    return l.substr(0, mn);
  }
  string process(vector<string> &v, int l, int r) {
    if (l == r) {
      return v[l];
    }
    int mid = (l + r) / 2;
    string left = process(v, l, mid);
    string right = process(v, mid + 1, r);
    return common_string(left, right);
  }
};

void solve() {
  vector<string> tc[] = {
      {"leetcode", "leet", "leet"},
      {"grammarly", "grammer", "grace", "grateful", "gradient"},
      {"greek", "greece", "green", "create"}};
  int nc = sizeof(tc) / sizeof(tc[0]);
  Solution solution;
  for (int i = 0; i < nc; i++) {
    cout << solution.longestCommonPrefix(tc[i]) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
