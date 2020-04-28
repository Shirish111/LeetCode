// Minimum Depth of Binary Tree

// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example:

// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.

// Tags: binary_tree, recursion

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
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (!root->left && !root->right) {
      return 1;  // Leaf Node
    } else if (root->left && root->right) {
      return 1 + min(minDepth(root->left), minDepth(root->right));
    } else if (root->left) {
      return 1 + minDepth(root->left);
    } else {
      return 1 + minDepth(root->right);
    }
  }
};
void solve() {}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
