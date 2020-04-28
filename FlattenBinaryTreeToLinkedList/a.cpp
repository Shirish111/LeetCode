// Flatten Binary Tree to Linked List

// Given a binary tree, flatten it to a linked list in-place.

// For example, given the following tree:

//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// The flattened tree should look like:

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6

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
  void flatten(TreeNode *root) {
    TreeNode *p, *q;
    p = root;
    while (p) {
      if (!p->left) {
        p = p->right;
        continue;
      }
      q = p->left;
      while (q && q->right) {
        q = q->right;
      }
      q->right = p->right;
      p->right = p->left;
      p->left = nullptr;
      p = p->right;
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
