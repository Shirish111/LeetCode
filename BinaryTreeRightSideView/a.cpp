// Binary Tree Right Side View

// Given a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.

// Example:

// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

// Tags: binary_tree, postorder, interview
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
  int mx;
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    mx = -1;
    postOrder(ans, root, 0);
    return ans;
  }
  void postOrder(vector<int> &ans, TreeNode *p, int cur) {
    if (!p) {
      return;
    }
    if (mx < cur) {
      mx = cur;
      ans.push_back(p->val);
    }
    postOrder(ans, p->right, cur + 1);
    postOrder(ans, p->left, cur + 1);
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
  vector<vector<int>> tc = {{1, 2, 3, INT_MAX, 5, INT_MAX, 4}};
  Solution s;
  for (auto &i : tc) {
    TreeNode *t = constructTree(i, 0);
    vector<int> ans = s.rightSideView(t);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
