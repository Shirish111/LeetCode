// Validate Binary Search Tree

// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's
// key. The right subtree of a node contains only nodes with keys greater than
// the node's key. Both the left and right subtrees must also be binary search
// trees.

// Example 1:

//     2
//    / \
//   1   3

// Input: [2,1,3]
// Output: true
// Example 2:

//     5
//    / \
//   1   4
//      / \
//     3   6

// Input: [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

// Tags: binary_search_tree, inorder

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class SolutionR {
 public:
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, LONG_LONG_MIN, LONG_LONG_MIN);
  }
  bool isValidBST(TreeNode *p, long long lower, long long upper) {
    if (p == nullptr) {
      return true;
    }
    if (lower != LONG_LONG_MIN && p->val <= lower) {
      return false;
    }
    if (upper != LONG_LONG_MIN && p->val >= upper) {
      return false;
    }
    if (!isValidBST(p->left, lower, p->val)) {
      return false;
    }
    if (!isValidBST(p->right, p->val, upper)) {
      return false;
    }
    return true;
  }
};

// Using inorder traversal
class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    vector<int> values_array;
    inorder(root, values_array);
    return adjacent_find(values_array.begin(), values_array.end(),
                         greater_equal<int>()) == values_array.end();
  }
  void inorder(TreeNode *p, vector<int> &a) {
    if (p) {
      inorder(p->left, a);
      a.push_back(p->val);
      inorder(p->right, a);
    }
  }
};
TreeNode *constructTree(vector<long long> &a, int i) {
  if (i >= a.size() || a[i] == LONG_LONG_MIN) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(a[i]);
  root->left = constructTree(a, 2 * i + 1);
  root->right = constructTree(a, 2 * i + 2);
  return root;
}
void solve() {
  vector<vector<long long>> tc = {{2, 1, 3},
                                  {5, 1, 4, LONG_LONG_MIN, LONG_LONG_MIN, 3, 6},
                                  {1, 1},
                                  {-2147483648, -2147483648}};
  Solution s;
  for (auto &i : tc) {
    TreeNode *root = constructTree(i, 0);
    cout << boolalpha << s.isValidBST(root) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
