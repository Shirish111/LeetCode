// Scramble String

// Given a string s1, we may represent it as a binary tree by partitioning it to
// two non-empty substrings recursively.

// Below is one possible representation of s1 = "great":

//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two
// children.

// For example, if we choose the node "gr" and swap its two children, it
// produces a scrambled string "rgeat".

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".

// Similarly, if we continue to swap the children of nodes "eat" and "at", it
// produces a scrambled string "rgtae".

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".

// Given two strings s1 and s2 of the same length, determine if s2 is a
// scrambled string of s1.

// Example 1:

// Input: s1 = "great", s2 = "rgeat"
// Output: true
// Example 2:

// Input: s1 = "abcde", s2 = "caebd"
// Output: false

// Tags: miscellaneous, recursion, string_manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    int n = s1.length();
    if (n != s2.length()) {
      return false;
    }
    if (s1 == s2) {
      return true;
    }
    vector<int> v1(26, 0), v2(26, 0);
    for (auto &i : s1) {
      v1[i - 'a']++;
    }
    for (auto &i : s2) {
      v2[i - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (v1[i] != v2[i]) {
        return false;
      }
    }
    for (int i = 1; i < n; i++) {
      if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
          isScramble(s1.substr(i), s2.substr(i))) {
        return true;
      }
      if ((isScramble(s1.substr(0, i), s2.substr(n - i)) &&
           isScramble(s1.substr(i), s2.substr(0, n - i)))) {
        return true;
      }
    }
    return false;
  }
};
void solve() {
  vector<pair<string, string>> tc = {{"great", "rgeat"}, {"great", "eatrg"},
                                     {"grea", "earg"},   {"abcde", "caebd"},
                                     {"great", "etarg"}, {"abb", "bab"}};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isScramble(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
