// Binary Tree Zigzag Level Order Traversal

// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

// Tags: binary_tree, recursion, interview
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
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
    for (int i = 1; i < ans.size(); i += 2) {
      reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
  }
};
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
      return ans;
    }
    stack<TreeNode *> s1, s2;
    TreeNode *p;
    vector<int> tmp;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
      tmp.clear();
      while (!s1.empty()) {
        p = s1.top();
        s1.pop();
        tmp.push_back(p->val);
        if (p->left) {
          s2.push(p->left);
        }
        if (p->right) {
          s2.push(p->right);
        }
      }
      ans.push_back(tmp);
      tmp.clear();
      while (!s2.empty()) {
        p = s2.top();
        s2.pop();
        tmp.push_back(p->val);
        if (p->right) {
          s1.push(p->right);
        }
        if (p->left) {
          s1.push(p->left);
        }
      }
      if (!tmp.empty()) {
        ans.push_back(tmp);
      }
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
