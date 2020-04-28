// Course Schedule II

// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to
// first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return
// the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If
// it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: 2, [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you
// should have finished
//              course 0. So the correct course order is [0,1] .
// Example 2:

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you
// should have finished both
//              courses 1 and 2. Both courses 1 and 2 should be taken after you
//              finished course 0. So one correct course order is [0,1,2,3].
//              Another correct ordering is [0,2,1,3] .
// Note:

// The input prerequisites is a graph represented by a list of edges, not
// adjacency matrices. Read more about how a graph is represented. You may
// assume that there are no duplicate edges in the input prerequisites.

// Tags: graph, dfs

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  using graph = vector<vector<int>>;
  vector<bool> visited;
  vector<bool> recursion;
  vector<int> findOrder(int n, vector<vector<int>>& edges) {
    graph g = buildGraph(edges, n);
    visited.assign(n, false);
    recursion.assign(n, false);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        if (dfs(ans, g, i)) {
          return vector<int>();
        }
      }
    }
    return ans;
  }
  bool dfs(vector<int>& ans, graph& g, int u) {
    visited[u] = true;
    recursion[u] = true;
    for (auto& v : g[u]) {
      if (!visited[v]) {
        if (dfs(ans, g, v)) {
          return true;
        }
      } else if (recursion[v]) {
        return true;
      }
    }
    recursion[u] = false;
    ans.push_back(u);
    return false;
  }
  graph buildGraph(vector<vector<int>>& edges, int vertices) {
    graph g(vertices);
    for (auto& i : edges) {
      g[i[0]].push_back(i[1]);
    }
    return g;
  }
};
void solve() {
  vector<pair<int, vector<vector<int>>>> tc = {
      {2, {{1, 0}}},
      {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}},
      {2, {{0, 1}, {1, 0}}}};
  Solution s;
  for (auto& i : tc) {
    vector<int> ans = s.findOrder(i.first, i.second);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
