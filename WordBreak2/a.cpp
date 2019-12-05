// Word Break II

// Given a non-empty string s and a dictionary wordDict containing a list of
// non-empty words, add spaces in s to construct a sentence where each word is a
// valid dictionary word. Return all such possible sentences.

// Note:

// The same word in the dictionary may be reused multiple times in the
// segmentation. You may assume the dictionary does not contain duplicate words.
// Example 1:

// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
// Example 2:

// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []

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
  vector<string> wordBreak(string &s, unordered_set<string> &dict) {
    unordered_map<int, vector<string>> m = {{s.length(), {""}}};
    function<vector<string>(int)> f = [&](int i) -> vector<string> {
      if (m.find(i) != m.end()) {
        return m[i];
      }
      for (int j = i + 1; j <= s.length(); j++) {
        string word = s.substr(i, j - i);
        if (dict.find(word) != dict.end()) {
          for (auto &tail : f(j)) {
            m[i].push_back(word + (tail == "" ? "" : " " + tail));
          }
        }
      }
      return m[i];
    };
    return f(0);
  }

 public:
  vector<string> wordBreak(string s, vector<string> &words) {
    unordered_set<string> dict;
    for (auto &i : words) {
      dict.insert(i);
    }
    return wordBreak(s, dict);
  }
};
void solve() {
  vector<pair<string, vector<string>>> tc = {
      {"leetcode", {"leet", "code"}},
      {"catsanddog", {"cat", "cats", "and", "sand", "dog"}},
      {"pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"}}};
  Solution s;
  for (auto &i : tc) {
    vector<string> ans = s.wordBreak(i.first, i.second);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
