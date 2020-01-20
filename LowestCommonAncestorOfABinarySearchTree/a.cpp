// Lowest Common Ancestor of a Binary Search Tree

// Given a binary search tree (BST), find the lowest common ancestor (LCA) of
// two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes p and q as the lowest node in T that has both p
// and q as descendants (where we allow a node to be a descendant of itself).”

// Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]

// Example 1:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.
// Example 2:

// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
// Output: 2
// Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant
// of itself according to the LCA definition.

// Note:

// All of the nodes' values will be unique.
// p and q are different and both values will exist in the BST.

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root) {
      if (p == root || q == root) {
        return root;
      }
      if ((p->val < root->val && q->val > root->val) ||
          (p->val > root->val && q->val < root->val)) {
        return root;
      }
      if (p->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
      }
      return lowestCommonAncestor(root->right, p, q);
    } else {
      return nullptr;
    }
  }
};
TreeNode* constructTree(vector<int>& a, int i) {
  if (i >= a.size() || a[i] == INT_MAX) {
    return nullptr;
  }
  TreeNode* r = new TreeNode(a[i]);
  r->left = constructTree(a, 2 * i + 1);
  r->right = constructTree(a, 2 * i + 2);
  return r;
}
TreeNode* findNode(TreeNode* r, int p) {
  if (r->val == p) {
    return r;
  }
  if (p < r->val) {
    return findNode(r->left, p);
  }
  return findNode(r->right, p);
}
struct Q {
  vector<int> t;
  int p, q;
};
void solve() {
  vector<Q> tc = {Q{{6, 2, 8, 0, 4, 7, 9, INT_MAX, INT_MAX, 3, 5}, 2, 8},
                  Q{{6, 2, 8, 0, 4, 7, 9, INT_MAX, INT_MAX, 3, 5}, 2, 4}};
  Solution s;
  for (auto& i : tc) {
    TreeNode* r = constructTree(i.t, 0);
    TreeNode* p = findNode(r, i.p);
    TreeNode* q = findNode(r, i.q);
    cout << r->val << " p" << p->val << " q" << q->val << "\n";
    cout << s.lowestCommonAncestor(r, p, q)->val << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
