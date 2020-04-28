// Substring with Concatenation of All Words

// You are given a string, s, and a list of words, words, that are all of the
// same length. Find all starting indices of substring(s) in s that is a
// concatenation of each word in words exactly once and without any intervening
// characters.

// Example 1:

// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
// respectively. The output order does not matter, returning [9,0] is fine too.
// Example 2:

// Input:
//   s = "wordgoodgoodgoodbestword",
//   words = ["word","good","best","word"]
// Output: []

// Tags: miscellaneous, string_manipulation, hashing

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string &s, vector<string> &words) {
    unordered_map<string, int> count;
    for (auto &i : words) {
      count[i]++;
    }
    vector<int> ans;
    if (words.size() == 0) {
      return ans;
    }
    int sl = s.length(), nw = words.size(), wl = words[0].length();
    int substr_len = nw * wl;
    for (int i = 0; i < sl - substr_len + 1; i++) {
      unordered_map<string, int> seen;
      int j = 0;
      while (j < nw) {
        string word = s.substr(i + j * wl, wl);
        auto ct = count.find(word);
        if (ct == count.end()) {
          break;
        }
        seen[word]++;
        auto st = seen.find(word);
        if (st->second > ct->second) {
          break;
        }
        j++;
      }
      if (j == nw) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
void solve() {
  vector<pair<string, vector<string>>> tc = {
      {"barfoothefoobarman", {"foo", "bar"}},
      {"wordgoodgoodgoodbestword", {"word", "good", "best", "good"}}};
  Solution solution;
  for (auto &i : tc) {
    vector<int> v = solution.findSubstring(i.first, i.second);
    for (auto &j : v) {
      cout << j << " ";
    }
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
