// Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same
// character but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
// Note:
// You may assume both s and t have the same length.

// Tags: hashing, miscellaneous

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> m(256, -1);
    vector<int> ms(256, -1), mt(256, -1);
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      if (ms[s[i]] != -1 && ms[s[i]] != t[i]) {
        return false;
      }
      if (mt[t[i]] != -1 && mt[t[i]] != s[i]) {
        return false;
      }
      ms[s[i]] = t[i];
      mt[t[i]] = s[i];
    }
    return true;
  }
};
void solve() {
  vector<pair<string, string>> tc = {
      {"egg", "add"}, {"foo", "bar"}, {"paper", "title"}, {"ab", "aa"}};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isIsomorphic(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
