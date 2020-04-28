// Combination Sum III

// Find all possible combinations of k numbers that add up to a number n, given
// that only numbers from 1 to 9 can be used and each combination should be a
// unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

// Tags: back_tracking, recursion
// Difficulty: Medium
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> comb;
    backtrack(ans, comb, 1, k, n);
    return ans;
  }
  void backtrack(vector<vector<int>>& ans, vector<int>& comb, int u, int k,
                 int n) {
    if (comb.size() == k) {
      if (n == 0) {
        ans.push_back(comb);
      }
      return;
    }
    for (int i = u; i <= 9; ++i) {
      if (n - i < 0) {
        return;
      }
      comb.push_back(i);
      backtrack(ans, comb, i + 1, k, n - i);
      comb.pop_back();
    }
  }
};
void solve() {
  vector<pair<int, int>> tc = {{3, 7}, {3, 9}};
  Solution s;
  for (auto& i : tc) {
    vector<vector<int>> ans = s.combinationSum3(i.first, i.second);
    for (auto& j : ans) {
      copy(j.begin(), j.end(), ostream_iterator<int>(cout, " "));
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
