// Binary Tree Postorder Traversal

// Given a binary tree, return the postorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [3,2,1]
// Follow up: Recursive solution is trivial, could you do it iteratively?

// Tags: binary_tree, postorder, stack
// Difficulty: Medium
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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (!root) {
      return ans;
    }
    TreeNode *p = root;
    stack<TreeNode *> s1;
    s1.push(p);
    while (!s1.empty()) {
      p = s1.top();
      s1.pop();
      ans.push_back(p->val);
      if (p->left) {
        s1.push(p->left);
      }
      if (p->right) {
        s1.push(p->right);
      }
    }
    reverse(ans.begin(), ans.end());
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
