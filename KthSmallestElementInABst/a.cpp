// Kth Smallest Element in a BST

// Given a binary search tree, write a function kthSmallest to find the kth
// smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// Output: 1
// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// Output: 3
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to
// find the kth smallest frequently? How would you optimize the kthSmallest
// routine?

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
  vector<int> a;
  int kthSmallest(TreeNode *root, int k) {
    inorder(root);
    return a[k - 1];
  }
  void inorder(TreeNode *t) {
    if (t) {
      inorder(t->left);
      a.push_back(t->val);
      inorder(t->right);
    }
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
  vector<pair<int, vector<int>>> tc = {
      {1, {3, 1, 4, INT_MAX, 2}}, {3, {5, 3, 6, 2, 4, INT_MAX, INT_MAX, 1}}};
  Solution s;
  for (auto &i : tc) {
    TreeNode *r = constructTree(i.second, 0);
    cout << s.kthSmallest(r, i.first) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
