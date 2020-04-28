// Combination Sum II

// Given a collection of candidate numbers (candidates) and a target number
// (target), find all unique combinations in candidates where the candidate
// numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

// Tags: back_tracking, recursion, interview
// Difficulty: Medium
// Important: Skipping duplicates by using i == beg || c[i] != c[i - 1]
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
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
    for (int i = beg; i < c.size() && target >= c[i]; i++) {
      if (i == beg || c[i] != c[i - 1]) {
        comb.push_back(c[i]);
        backtrack(res, c, target - c[i], comb, i + 1);
        comb.pop_back();
      }
    }
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{10, 1, 2, 7, 6, 1, 5}, 8},
                                       {{2, 5, 2, 1, 2}, 5}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> res = s.combinationSum2(i.first, i.second);
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
