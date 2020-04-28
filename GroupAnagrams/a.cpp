// Group Anagrams

// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

// Tags: sorting, hashing

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    int n = strs.size();
    for (int i = 0; i < n; i++) {
      string s = strs[i];
      sort(s.begin(), s.end());
      m[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto &i : m) {
      ans.push_back(i.second);
    }
    return ans;
  }
};
void solve() {
  vector<vector<string>> tc = {{"eat", "tea", "tan", "ate", "nat", "bat"}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<string>> ans = s.groupAnagrams(i);
    for (auto &i : ans) {
      for (auto &j : i) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
