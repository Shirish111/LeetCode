// Balanced Binary Tree

// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in
// height by no more than 1.

// Example 1:

// Given the following tree [3,9,20,null,null,15,7]:

//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.

// Example 2:

// Given the following tree [1,2,2,3,3,null,null,4,4]:

//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

// Tags: binary_tree, recursion
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
  bool isBalanced(TreeNode *root) {
    bool bflag = true;
    validate(root, bflag);
    return bflag;
  }
  int validate(TreeNode *p, bool &bflag) {
    if (bflag == false || p == nullptr) {
      return 0;
    }
    int left, right;
    left = validate(p->left, bflag);
    if (bflag) {
      right = validate(p->right, bflag);
    }
    bflag = bflag && (abs(left - right) <= 1);
    return max(left, right) + 1;
  }
};
void solve() {}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
