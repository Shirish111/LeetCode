// Binary Tree Maximum Path Sum

// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some
// starting node to any node in the tree along the parent-child connections. The
// path must contain at least one node and does not need to go through the root.

// Example 1:

// Input: [1,2,3]

//        1
//       / \
//      2   3

// Output: 6
// Example 2:

// Input: [-10,9,20,null,null,15,7]

//    -10
//    / \
//   9  20
//     /  \
//    15   7

// Output: 42

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
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int maxPathSum(TreeNode *root) {
    int mx = INT_MIN;
    maxPathSum(root, mx);
    return mx;
  }
  int maxPathSum(TreeNode *root, int &mx) {
    int leftSum = root->left ? max(0, maxPathSum(root->left, mx)) : 0;
    int rightSum = root->right ? max(0, maxPathSum(root->right, mx)) : 0;
    mx = max(mx, root->val + leftSum + rightSum);
    return max(root->val, root->val + max(leftSum, rightSum));
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
  vector<vector<int>> tc = {
      {1, 2, 3}, {-10, 9, 20, INT_MAX, INT_MAX, 15, 7}, {2, -1}};
  Solution s;
  for (auto &i : tc) {
    TreeNode *root = constructTree(i, 0);
    cout << s.maxPathSum(root) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
