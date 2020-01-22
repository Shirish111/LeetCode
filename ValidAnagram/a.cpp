// Valid Anagram

// Given two strings s and t , write a function to determine if t is an anagram
// of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your
// solution to such case?

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> a(26, 0);
    for (auto &i : s) {
      a[i - 'a']++;
    }
    for (auto &i : t) {
      a[i - 'a']--;
    }
    for (auto &i : a) {
      if (i) {
        return false;
      }
    }
    return true;
  }
};
void solve() {
  vector<pair<string, string>> tc = {{"car", "rat"}, {"anagram", "ngaaram"}};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isAnagram(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
