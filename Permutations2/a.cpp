// Permutations II

// Given a collection of numbers that might contain duplicates, return all
// possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
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
  int n;
  vector<vector<int>> permuteUnique(vector<int>& a) {
    vector<vector<int>> res;
    n = a.size();
    _permute(res, a, 0);
    return res;
  }
  void _permute(vector<vector<int>>& res, vector<int> a, int l) {
    if (l == n) {
      res.push_back(a);
      return;
    }
    for (int i = l; i < n; i++) {
      if (!should_swap(a, l, i)) {
        continue;
      }
      swap(a[i], a[l]);
      _permute(res, a, l + 1);
      swap(a[i], a[l]);
    }
  }
  bool should_swap(vector<int>& a, int start, int cur) {
    for (int i = start; i < cur; i++) {
      if (a[i] == a[cur]) {
        return 0;
      }
    }
    return true;
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 1, 1}, {1, 1, 2, 2}, {0, 0, 0, 1, 9}};
  Solution s;
  for (auto& i : tc) {
    vector<vector<int>> res = s.permuteUnique(i);
    cout << "cnt = " << res.size() << "\n";
    for (auto& j : res) {
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
