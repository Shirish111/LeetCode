// Construct Binary Tree from Preorder and Inorder Traversal

// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    n = inorder.size();
    for (int i = 0; i < n; i++) {
      inMap[inorder[i]] = i;
    }
    return buildTree(preorder, inorder, 0, 0, n - 1);
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                      int pre_start, int in_start, int in_end) {
    if (pre_start == n) {
      return nullptr;
    }
    if (in_start > in_end) {
      return nullptr;
    }
    int in_index = inMap[preorder[pre_start]];
    TreeNode* root;
    root = new TreeNode(preorder[pre_start]);
    int leftTreeLen = in_index - in_start;
    root->left =
        buildTree(preorder, inorder, pre_start + 1, in_start, in_index - 1);
    root->right = buildTree(preorder, inorder, pre_start + leftTreeLen + 1,
                            in_index + 1, in_end);
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
