// Subsets

// Given a set of distinct integers, nums, return all possible subsets (the
// power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// Tags: back_tracking, recursion, subset

#include <bits/stdc++.h>
using namespace std;

// Using Backtracking
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& a) {
    vector<vector<int>> ans;
    int n = a.size();
    sort(a.begin(), a.end());
    vector<int> subset;
    subsets(ans, a, subset, n, 0);
    return ans;
  }
  void subsets(vector<vector<int>>& ans, vector<int>& a, vector<int>& subset,
               int n, int beg) {
    ans.push_back(subset);
    for (int i = beg; i < n; i++) {
      if (i > beg && a[i] == a[i - 1]) {
        continue;
      }
      subset.push_back(a[i]);
      subsets(ans, a, subset, n, i + 1);
      subset.pop_back();
    }
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 3}, {1, 1, 2, 2}};
  Solution s;
  for (auto& i : tc) {
    vector<vector<int>> ans = s.subsets(i);
    for (auto& j : ans) {
      copy(j.begin(), j.end(), ostream_iterator<int>(cout, " "));
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
