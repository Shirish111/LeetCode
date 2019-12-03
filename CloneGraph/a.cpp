// Clone Graph

// Given a reference of a node in a connected undirected graph, return a deep
// copy (clone) of the graph. Each node in the graph contains a val (int) and a
// list (List[Node]) of its neighbors.

// Example:

// Input:
// {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}

// Explanation:
// Node 1's value is 1, and it has two neighbors: Node 2 and 4.
// Node 2's value is 2, and it has two neighbors: Node 1 and 3.
// Node 3's value is 3, and it has two neighbors: Node 2 and 4.
// Node 4's value is 4, and it has two neighbors: Node 1 and 3.

// Note:

// The number of nodes will be between 1 and 100.
// The undirected graph is a simple graph, which means no repeated edges and no
// self-loops in the graph. Since the graph is undirected, if node p has node q
// as neighbor, then node q must have node p as neighbor too. You must return
// the copy of the given node as a reference to the cloned graph.

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

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {}

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return node;
    }
    queue<Node*> q;
    Node* root = new Node();
    unordered_map<Node*, Node*> visited;
    q.push(node);
    visited[node] = root;
    while (!q.empty()) {
      Node* old = q.front();
      q.pop();
      Node* cur = visited[old];
      cur->val = old->val;
      for (auto& oldnode : old->neighbors) {
        if (!visited[oldnode]) {
          Node* newnode = new Node();
          cur->neighbors.push_back(newnode);
          q.push(oldnode);
          visited[oldnode] = newnode;
        } else {
          cur->neighbors.push_back(visited[oldnode]);
        }
      }
    }
    return root;
  }
};
void solve() {}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
