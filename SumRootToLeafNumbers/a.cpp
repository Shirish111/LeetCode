// Sum Root to Leaf Numbers

// Given a binary tree containing digits from 0-9 only, each root-to-leaf path
// could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// Note: A leaf is a node with no children.

// Example:

// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
// Example 2:

// Input: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.

// Tags: binary_tree, path_sum

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
  int sumNumbers(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int sm = 0;
    sum(root, sm, 0);
    return sm;
  }
  void sum(TreeNode *root, int &sm, int cur) {
    if (root->left == nullptr && root->right == nullptr) {
      sm += cur + root->val;
      return;
    }
    cur += root->val;
    if (root->left) {
      sum(root->left, sm, cur * 10);
    }
    if (root->right) {
      sum(root->right, sm, cur * 10);
    }
  }
};
TreeNode *constructTree(vector<int> &a, int i) {
  if (i >= a.size() || a[i] == INT_MAX) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(a[i]);
  root->left = constructTree(a, 2 * i + 1);
  root->right = constructTree(a, 2 * i + 2);
  return root;
}
void solve() {
  vector<vector<int>> tc = {{1, 2, 3}, {4, 9, 0, 5, 1}};
  Solution s;
  for (auto &i : tc) {
    TreeNode *root = constructTree(i, 0);
    cout << s.sumNumbers(root) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
