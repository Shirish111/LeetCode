// Lowest Common Ancestor of a Binary Tree

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
// in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes p and q as the lowest node in T that has both p
// and q as descendants (where we allow a node to be a descendant of itself).”

// Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
// of itself according to the LCA definition.

// Note:

// All of the nodes' values will be unique.
// p and q are different and both values will exist in the binary tree.

// Tags: lca, binary_tree

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
  TreeNode* ans;
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    ans = nullptr;
    traverse(root, p, q);
    return ans;
  }
  bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return false;
    }
    if (ans != nullptr) {
      return false;
    }
    bool mid = root == p || root == q;
    bool left = traverse(root->left, p, q);
    if (mid && left) {
      ans = root;
      return true;
    }
    bool right = traverse(root->right, p, q);
    if (mid + left + right == 2) {
      ans = root;
      return true;
    }
    return mid || left || right;
  }
};
TreeNode* constructTree(vector<int>& a, int i) {
  if (i >= a.size() || a[i] == INT_MAX) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(a[i]);
  root->left = constructTree(a, 2 * i + 1);
  root->right = constructTree(a, 2 * i + 2);
  return root;
}
TreeNode* findNode(TreeNode* root, int p) {
  if (root) {
    if (p == root->val) {
      return root;
    }
    TreeNode* desc = findNode(root->left, p);
    if (desc) {
      return desc;
    }
    desc = findNode(root->right, p);
    if (desc) {
      return desc;
      ;
    }
    return nullptr;
  } else {
    return nullptr;
  }
}
struct Q {
  vector<int> t;
  int p, q;
};
void solve() {
  vector<Q> tc = {Q{{3, 5, 1, 6, 2, 0, 8, INT_MAX, INT_MAX, 7, 4}, 5, 1}};
  Solution s;
  for (auto& i : tc) {
    TreeNode* r = constructTree(i.t, 0);
    TreeNode* p = findNode(r, i.p);
    TreeNode* q = findNode(r, i.q);
    cout << s.lowestCommonAncestor(r, p, q)->val << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
