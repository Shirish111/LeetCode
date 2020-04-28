// Minimum Window Substring

// Given a string S and a string T, find the minimum window in S which will
// contain all the characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the
// empty string "". If there is such window, you are guaranteed that there will
// always be only one unique minimum window in S.

// Tags: miscellaneous, string_manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string minWindow(string &s, string &t) {
    vector<int> m(128, 0);
    for (auto &c : t) {
      m[c]++;  // Store count of each character in string t
    }
    int tn = t.length(), sn = s.length(), head = 0, left = 0, right = 0,
        mn = INT_MAX;
    while (right < sn) {
      if (m[s[right++]]-- >
          0) {  // If s[right] is present in t and m[s[right]] > 0 then decrease
                // tn. decrement m[s[right]] by 1
        tn--;   // Negative m[s[right]] indicates that the substring has more
                // than required number of char s[right]
      }
      while (tn == 0) {  // Valid substring
        if (mn > right - left) {
          mn = right - left;
          head = left;
        }
        m[s[left]]++;  // Moving left ptr towards right so increment m[s[left]]
                       // by 1
        if (m[s[left]] > 0) {
          tn++;
        }
        left++;  // Contract the window(left, right) by incrementing left
      }
    }
    return mn == INT_MAX ? "" : s.substr(head, mn);
  }
};
void solve() {
  vector<pair<string, string>> tc = {{"ADOBECODEBANC", "ABC"}};
  Solution s;
  for (auto &i : tc) {
    cout << s.minWindow(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
