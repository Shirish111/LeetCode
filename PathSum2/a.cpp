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

// Tags: binary_tree, path_sum, recursion

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
