// Path Sum II

// Given a binary tree and a sum, find all root-to-leaf paths where each path's
// sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:

// Given the below binary tree and sum = 22,

//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
// Return:

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> ans;
    vector<int> comb;
    pathSum(ans, comb, root, sum);
    return ans;
  }
  void pathSum(vector<vector<int>> &ans, vector<int> &comb, TreeNode *root,
               int sum) {
    if (root == nullptr) {
      return;
    }
    sum -= root->val;
    comb.push_back(root->val);
    if (!root->left && !root->right) {
      if (sum == 0) {
        ans.push_back(comb);
      }
    } else {
      if (root->left) {
        pathSum(ans, comb, root->left, sum);
      }
      if (root->right) {
        pathSum(ans, comb, root->right, sum);
      }
    }
    comb.pop_back();
  }
};
void solve() {}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
