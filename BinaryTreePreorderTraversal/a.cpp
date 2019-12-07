// Binary Tree Preorder Traversal

// Given a binary tree, return the preorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,2,3]
// Follow up: Recursive solution is trivial, could you do it iteratively?

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

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (!root) {
      return ans;
    }
    stack<TreeNode *> s;
    TreeNode *p = root;
    s.push(p);
    while (!s.empty()) {
      p = s.top();
      s.pop();
      ans.push_back(p->val);
      if (p->right) {
        s.push(p->right);
      }
      if (p->left) {
        s.push(p->left);
      }
    }
    return ans;
  }
};
void solve() {}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
