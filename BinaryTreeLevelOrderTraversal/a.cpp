// Binary Tree Level Order Traversal

// Given a binary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

// Tags: binary_tree, level_order, queue
// Difficulty: Easy
// Important: You can differentiate between the levels of binary tree in level
// order traversal by using queue size in the loop
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
  vector<vector<int>> levelOrder(TreeNode *root) {
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
      if (ans.size() == p.second) {
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
    return ans;
  }
};

class Solution2 {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    queue<TreeNode *> q;
    TreeNode *p;
    q.push(root);
    while (!q.empty()) {
      int cnt = q.size();
      vector<int> v;
      while (cnt--) {
        p = q.front();
        v.push_back(p->val);
        q.pop();
        if (p->left) {
          q.push(p->left);
        }
        if (p->right) {
          q.push(p->right);
        }
      }
      ans.push_back(v);
    }
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
