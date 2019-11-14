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
