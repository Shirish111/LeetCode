// Flower Planting With No Adjacent

// You have N gardens, labelled 1 to N.  In each garden, you want to plant one
// of 4 types of flowers.

// paths[i] = [x, y] describes the existence of a bidirectional path from garden
// x to garden y.

// Also, there is no garden that has more than 3 paths coming into or leaving
// it.

// Your task is to choose a flower type for each garden such that, for any two
// gardens connected by a path, they have different types of flowers.

// Return any such a choice as an array answer, where answer[i] is the type of
// flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3,
// or 4.  It is guaranteed an answer exists.

// Example 1:

// Input: N = 3, paths = [[1,2],[2,3],[3,1]]
// Output: [1,2,3]
// Example 2:

// Input: N = 4, paths = [[1,2],[3,4]]
// Output: [1,2,1,2]
// Example 3:

// Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
// Output: [1,2,3,4]

// Note:

// 1 <= N <= 10000
// 0 <= paths.size <= 20000
// No garden has 4 or more paths coming into or leaving it.
// It is guaranteed an answer exists.
// Tags: Tricky, Graph
// Difficulty: Medium
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    vector<vector<int>> g(n);
    for (auto &i : paths) {
      g[i[0] - 1].push_back(i[1] - 1);
      g[i[1] - 1].push_back(i[0] - 1);
    }
    vector<int> nodes(n, 0);
    vector<int> color;
    for (int u = 0; u < n; ++u) {
      color.assign(5, 0);
      for (auto &v : g[u]) {
        color[nodes[v]] = 1;
      }
      for (int i = 4; i >= 1; --i) {
        if (!color[i]) {
          nodes[u] = i;
          break;
        }
      }
    }
    return nodes;
  }
};

void solve() {
  vector<pair<int, vector<vector<int>>>> tc = {
      {3, {{1, 2}, {2, 3}, {3, 1}}},
      {4, {{1, 2}, {3, 4}}},
      {4, {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}}}};
  Solution s;
  for (auto &i : tc) {
    vector<int> ans = s.gardenNoAdj(i.first, i.second);
    for (auto &j : ans) {
      cout << j << " ";
    }
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
