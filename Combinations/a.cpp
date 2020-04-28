// Combinations

// Given two integers n and k, return all possible combinations of k numbers out
// of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// Tags: back_tracking, recursion
// Difficulty: Medium
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb;
    combine(ans, comb, n, k, 1);
    return ans;
  }
  void combine(vector<vector<int>> &ans, vector<int> &comb, int n, int k,
               int beg) {
    if (comb.size() == k) {
      ans.push_back(comb);
      return;
    }
    for (int i = beg; i <= n; i++) {
      comb.push_back(i);
      combine(ans, comb, n, k, i + 1);
      comb.pop_back();
    }
  }
};
void solve() {
  vector<pair<int, int>> tc = {{4, 2}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> ans = s.combine(i.first, i.second);
    for (auto &i : ans) {
      copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
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
