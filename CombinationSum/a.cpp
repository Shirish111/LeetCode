// Combination Sum

// Given a set of candidate numbers (candidates) (without duplicates) and a
// target number (target), find all unique combinations in candidates where the
// candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of
// times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

// Tags: back_tracking, recursion
// Difficulty: Medium
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> comb;
    backtrack(res, candidates, target, comb, 0);
    return res;
  }
  void backtrack(vector<vector<int>> &res, vector<int> &c, int target,
                 vector<int> &comb, int beg) {
    if (target == 0) {
      res.push_back(comb);
      return;
    }
    for (int i = beg; i < (int)c.size() && target >= c[i]; i++) {
      comb.push_back(c[i]);
      backtrack(res, c, target - c[i], comb, i);
      comb.pop_back();
    }
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{2, 3, 6, 7}, 7}, {{2, 3, 5}, 8}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> res = s.combinationSum(i.first, i.second);
    for (auto &j : res) {
      for (auto &k : j) {
        cout << k << " ";
      }
      cout << "\n";
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
