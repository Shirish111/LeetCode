// Construct Binary Tree from Inorder and Postorder Traversal

// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define PB push_back
#define F0(I, N) for (ll I = 0; I < N; I++)
#define F1(I, N) for (ll I = 1; I <= N; I++)
#define F(I, X, N) for (ll I = X; I < N; I++)
#define R0(I, N) for (ll I = N - 1; I >= 0; I--)
#define R1(I, N) for (ll I = N; I > 0; I--)
#define R(I, X, N) for (ll I = N - 1; I >= X; I--)
#define A(X) X.begin(), X.end()

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int n;
  unordered_map<int, int> inMap;
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    n = inorder.size();
    for (int i = 0; i < n; i++) {
      inMap[inorder[i]] = i;
    }
    return buildTree(inorder, postorder, n - 1, 0, n - 1);
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                      int post_end, int in_start, int in_end) {
    if (in_start > in_end) {
      return nullptr;
    }
    if (post_end < 0) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(postorder[post_end]);
    int in_index = inMap[postorder[post_end]];
    int rightTreeLen = in_end - in_index;
    root->right =
        buildTree(inorder, postorder, post_end - 1, in_index + 1, in_end);
    root->left = buildTree(inorder, postorder, post_end - rightTreeLen - 1,
                           in_start, in_index - 1);
    return root;
  }
};
void inorder(TreeNode* p) {
  if (p) {
    inorder(p->left);
    cout << p->val << " ";
    inorder(p->right);
  }
}
void solve() {
  vector<pair<vector<int>, vector<int>>> tc = {
      {{3, 9, 20, 15, 7}, {9, 3, 15, 20, 7}}};
  Solution s;
  for (auto& i : tc) {
    TreeNode* root = s.buildTree(i.first, i.second);
    inorder(root);
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
