// Word Break

// Given a non-empty string s and a dictionary wordDict containing a list of
// non-empty words, determine if s can be segmented into a space-separated
// sequence of one or more dictionary words.

// Note:

// The same word in the dictionary may be reused multiple times in the
// segmentation. You may assume the dictionary does not contain duplicate words.
// Example 1:

// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple
// pen apple".
//              Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false

// Tags: miscellaneous, set, string_manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string> wordDict) {
    int n = s.length();
    set<string> dict;
    for (auto &i : wordDict) {
      dict.insert(i);
    }
    vector<bool> f(n + 1, false);
    f[0] = true;
    for (int i = 1; i <= s.length(); i++) {
      for (int j = 0; j < i; j++) {
        if (f[j] && (dict.find(s.substr(j, i - j)) != dict.end())) {
          f[i] = true;
          break;
        }
      }
    }
    return f[s.length()];
  }
};
void solve() {
  vector<pair<string, vector<string>>> tc = {{"leetcode", {"leet", "code"}},
                                             {"bbb", {"b", "a", "bb", "bbbb"}}};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.wordBreak(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
