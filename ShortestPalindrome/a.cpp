// Shortest Palindrome

// Given a string s, you are allowed to convert it to a palindrome by adding
// characters in front of it. Find and return the shortest palindrome you can
// find by performing this transformation.

// Example 1:

// Input: "aacecaaa"
// Output: "aaacecaaa"
// Example 2:

// Input: "abcd"
// Output: "dcbabcd"

// Tags: palindrome, miscellaneous, string_manipulation

#include <bits/stdc++.h>
using namespace std;

class SolutionBF {
 public:
  // Brute Force
  string shortestPalindrome(string s) {
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < n; ++i) {
      if (s.substr(0, n - i) == rev.substr(i)) {
        return rev.substr(0, i) + s;
      }
    }
    return "";
  }
};
// Two Pointer and Recursion
class SolutionTP {
 public:
  string shortestPalindrome(string s) {
    int n = s.size();
    int i = 0;
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == s[j]) {
        i++;
      }
    }
    if (i == n) {
      return s;
    }
    string remain_rev = s.substr(i, n);
    reverse(remain_rev.begin(), remain_rev.end());
    return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
  }
};
// KMP
class Solution {
 public:
  string shortestPalindrome(string s) {
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + '#' + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; ++i) {
      int t = f[i - 1];
      while (t > 0 && s_new[i] != s_new[t]) {
        t = f[t - 1];
      }
      if (s_new[i] == s_new[t]) {
        ++t;
        f[i] = t;
      }
    }
    return rev.substr(0, n - f[n_new - 1]) + s;
  }
};
void solve() {
  vector<string> tc = {"aacecaaa", "abcd"};
  Solution s;
  for (auto &i : tc) {
    cout << s.shortestPalindrome(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
