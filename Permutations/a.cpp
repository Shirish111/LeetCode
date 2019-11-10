// Permutations

// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
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

class Solution1 {
 public:
  int n;
  vector<vector<int>> permute(vector<int>& a) {
    vector<vector<int>> res;
    n = a.size();
    _permute(res, a, 0);
    return res;
  }
  void _permute(vector<vector<int>>& res, vector<int>& a, int l) {
    if (l == n) {
      res.push_back(a);
      return;
    }
    for (int i = l; i < n; i++) {
      swap(a[i], a[l]);
      _permute(res, a, l + 1);
      swap(a[i], a[l]);
    }
  }
};
class Solution {
 public:
  int n;
  vector<vector<int>> permute(vector<int>& a) {
    vector<vector<int>> res;
    n = a.size();
    vector<bool> visited(n, false);
    vector<int> v(n);
    backtrack(res, visited, a, v, 0);
    return res;
  }
  void backtrack(vector<vector<int>>& res, vector<bool>& visited,
                 vector<int>& a, vector<int>& v, int l) {
    if (l == n) {
      res.push_back(v);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        visited[i] = true;
        v[l] = a[i];
        backtrack(res, visited, a, v, l + 1);
        visited[i] = false;
      }
    }
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 3}};
  Solution s;
  for (auto& i : tc) {
    vector<vector<int>> res = s.permute(i);
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
