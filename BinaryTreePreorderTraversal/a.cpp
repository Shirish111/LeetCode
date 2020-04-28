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

// Tags: binary_tree, preorder
// Difficulty: Easy
// Status: Done

#include <bits/stdc++.h>
using namespace std;

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
