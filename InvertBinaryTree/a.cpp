// Invert Binary Tree

// Invert a binary tree.

// Example:

// Input:

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// Output:

//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
// Trivia:
// This problem was inspired by this original tweet by Max Howell:

// Google: 90% of our engineers use the software you wrote (Homebrew), but you
// can’t invert a binary tree on a whiteboard so f*** off.

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
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
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
void inorder(TreeNode* p) {
  if (p) {
    inorder(p->left);
    cout << p->val << " ";
    inorder(p->right);
  }
}
void solve() {
  vector<vector<int>> tc = {{4, 2, 7, 1, 3, 6, 9}};
  Solution s;
  for (auto& i : tc) {
    TreeNode* r = constructTree(i, 0);
    cout << "Before: "
         << "\n";
    inorder(r);
    r = s.invertTree(r);
    cout << "\n"
         << "After: "
         << "\n";
    inorder(r);
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
