// Convert Sorted Array to Binary Search Tree

// Given an array where elements are sorted in ascending order, convert it to a
// height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.

// Example:

// Given the sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following
// height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

// Tags: binary_search_tree

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& a) {
    int n = a.size();
    return buildTree(a, 0, n - 1);
  }
  TreeNode* buildTree(vector<int>& a, int low, int high) {
    if (low > high) {
      return nullptr;
    }
    int mid = (low + high) / 2;
    TreeNode* root = new TreeNode(a[mid]);
    root->left = buildTree(a, low, mid - 1);
    root->right = buildTree(a, mid + 1, high);
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
