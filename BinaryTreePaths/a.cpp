// Binary Tree Paths

// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

// Tags: binary_tree, recursion
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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res;
    vector<int> path;
    dfs(root, res, path);
    return res;
  }
  void dfs(TreeNode *p, vector<string> &res, vector<int> &path) {
    if (p == nullptr) {
      return;
    }
    path.push_back(p->val);
    if (p->left == nullptr && p->right == nullptr) {
      if (path.empty()) {
        return;
      }
      string ans = to_string(path[0]);
      for (int i = 1; i < path.size(); ++i) {
        ans.append("->" + to_string(path[i]));
      }
      res.push_back(ans);
      path.pop_back();
      return;
    }
    if (p->left) {
      dfs(p->left, res, path);
    }
    if (p->right) {
      dfs(p->right, res, path);
    }
    path.pop_back();
  }
};

void solve() {
  TreeNode *t = new TreeNode(1);
  t->left = new TreeNode(2);
  t->right = new TreeNode(3);
  t->left->right = new TreeNode(5);
  Solution s;
  vector<string> ans = s.binaryTreePaths(t);
  for (auto &i : ans) {
    cout << i << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
