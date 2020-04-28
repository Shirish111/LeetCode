// Implement strStr()

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Clarification:

// What should we return when needle is an empty string? This is a great
// question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty
// string. This is consistent to C's strstr() and Java's indexOf().

// Tags: kmp, string_manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
 public:
  // Using Brute Force method
  int strStr(string& s, string& p) {
    int sl = s.length();
    int pl = p.length();
    if (pl > sl) {
      return -1;
    }
    if (pl == 0) {
      return 0;
    }
    int pi, si;
    pi = si = 0;
    while (si < sl && pi < pl) {
      if (s[si] == p[pi]) {
        si++;
        pi++;
      } else if (pi == 0) {
        si++;
      } else {
        si = si - (pi - 1);
        pi = 0;
      }
    }
    if (pi == pl) {
      return si - pi;
    }
    return -1;
  }
};
class Solution {
 public:
  // Using KMP
  int strStr(string& s, string& p) {
    int sl = s.length(), pl = p.length();
    if (pl == 0) {
      return 0;
    }
    vector<int> v;
    preprocess(v, p, pl);
    int si = 0, pi = 0;
    while (si < sl && pi < pl) {
      if (s[si] == p[pi]) {
        si++;
        pi++;
      } else if (pi == 0) {
        si++;
      } else {
        pi = v[pi - 1];
      }
    }
    if (pi == pl) {
      return si - pi;
    }
    return -1;
  }
  void preprocess(vector<int>& v, string& p, int pl) {
    int i = 0, j = 1;
    v.resize(pl);
    v[0] = 0;
    while (j < pl) {
      if (p[i] == p[j]) {
        v[j] = i + 1;
        i++;
        j++;
      } else if (i == 0) {
        j++;
      } else {
        i = v[i - 1];
      }
    }
  }
};
void solve() {
  vector<pair<string, string>> tc = {{"abcdef", "bcd"},
                                     {"abcdef", "g"},
                                     {"abcdef", "abb"},
                                     {"yyyyz", "yyyz"},
                                     {"hello", "ll"},
                                     {"aaaaa", "bba"},
                                     {"ababcaababcaabc", "ababcaabc"}};
  Solution solution;
  int nt = tc.size();
  for (int i = 0; i < nt; i++) {
    cout << tc[i].first << " " << tc[i].second << " "
         << solution.strStr(tc[i].first, tc[i].second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
