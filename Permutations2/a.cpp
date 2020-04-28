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

class Solution1 {
 public:
  int n;
  vector<vector<int>> permuteUnique(vector<int>& a) {
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
        return false;
      }
    }
    return true;
  }
};
class Solution {
 public:
  int n;
  vector<vector<int>> permuteUnique(vector<int>& a) {
    n = a.size();
    vector<vector<int>> res;
    if (n == 0) {
      return res;
    }
    sort(a.begin(), a.end());
    vector<int> v(n);
    vector<bool> visited(n, false);
    backtrack(res, a, v, visited, 0);
    return res;
  }
  void backtrack(vector<vector<int>>& res, vector<int>& a, vector<int>& v,
                 vector<bool>& visited, int l) {
    if (l == n) {
      res.push_back(v);
      return;
    }
    for (int i = 0; i < n; i++) {
      if ((visited[i]) || (i > 0 && a[i] == a[i - 1] && !visited[i - 1])) {
        continue;
      }
      visited[i] = true;
      v[l] = a[i];
      backtrack(res, a, v, visited, l + 1);
      visited[i] = false;
    }
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
