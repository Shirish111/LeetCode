// Subsets II

// Given a collection of integers that might contain duplicates, nums, return
// all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

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
  vector<vector<int>> subsetsWithDup(vector<int>& a) {
    vector<vector<int>> res;
    vector<int> subset;
    sort(a.begin(), a.end());
    backtrack(res, a, subset, a.size(), 0);
    return res;
  }
  void backtrack(vector<vector<int>>& res, vector<int>& a, vector<int>& subset,
                 int n, int beg) {
    res.push_back(subset);
    for (int i = beg; i < n; i++) {
      if (i > beg && a[i - 1] == a[i]) {
        continue;
      }
      subset.push_back(a[i]);
      backtrack(res, a, subset, n, i + 1);
      subset.pop_back();
    }
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 2}};
  Solution s;
  for (auto& i : tc) {
    vector<vector<int>> ans = s.subsetsWithDup(i);
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
