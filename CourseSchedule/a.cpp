// Course Schedule

// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to
// first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it
// possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0. So it is
//              possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0, and to take
//              course 0 you should also have finished course 1. So it is
//              impossible.
// Note:

// The input prerequisites is a graph represented by a list of edges, not
// adjacency matrices. Read more about how a graph is represented. You may
// assume that there are no duplicate edges in the input prerequisites.

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
  vector<bool> visited, recursion;
  bool canFinish(int n, vector<vector<int>>& p) {
    vector<vector<int>> g(n, vector<int>());
    for (auto& i : p) {
      g[i[0]].push_back(i[1]);
    }
    return !detectCycle(g, n);
  }
  bool detectCycle(vector<vector<int>>& g, int n) {
    visited.assign(n, false);
    recursion.assign(n, false);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        if (dfs(g, i)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<int>>& g, int u) {
    visited[u] = true;
    recursion[u] = true;
    for (auto& v : g[u]) {
      if (!visited[v]) {
        if (dfs(g, v)) {
          return true;
        }
      } else if (recursion[v]) {
        return true;
      }
    }
    recursion[u] = false;
    return false;
  }
};
void solve() {
  vector<pair<int, vector<vector<int>>>> tc = {{2, {{}, {0}}}, {2, {{1}, {0}}}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.canFinish(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
