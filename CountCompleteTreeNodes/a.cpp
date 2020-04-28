// Count Complete Tree Nodes

// Given a complete binary tree, count the number of nodes.

// Note:

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is
// completely filled, and all nodes in the last level are as far left as
// possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Example:

// Input:
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6

// Tags: binary_tree

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
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
TreeNode* constructTree(vector<int>& a, int i) {
  if (i >= a.size() || a[i] == INT_MAX) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(a[i]);
  root->left = constructTree(a, 2 * i + 1);
  root->right = constructTree(a, 2 * i + 2);
  return root;
}
void solve() {
  vector<vector<int>> tc = {{1, 2, 3, 4, 5, 6, INT_MAX}};
  Solution s;
  for (auto& i : tc) {
    TreeNode* t = constructTree(i, 0);
    cout << s.countNodes(t) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
