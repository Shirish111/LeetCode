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
