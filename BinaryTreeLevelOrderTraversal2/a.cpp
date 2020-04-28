// Binary Tree Level Order Traversal II

// Given a binary tree, return the bottom-up level order traversal of its nodes'
// values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

// Tags: level_order, binary_tree
// Difficulty: Easy
// Status: Done

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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    queue<pair<TreeNode *, int>> q;
    pair<TreeNode *, int> p;
    q.push({root, 0});
    while (!q.empty()) {
      p = q.front();
      q.pop();
      if (p.second == ans.size()) {
        ans.push_back(vector<int>());
      }
      ans[p.second].push_back(p.first->val);
      if (p.first->left) {
        q.push({p.first->left, p.second + 1});
      }
      if (p.first->right) {
        q.push({p.first->right, p.second + 1});
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
void solve() {}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
