// Recover Binary Search Tree

// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Example 1:

// Input: [1,3,null,null,2]

//    1
//   /
//  3
//   \
//    2

// Output: [3,1,null,null,2]

//    3
//   /
//  1
//   \
//    2
// Example 2:

// Input: [3,1,4,null,null,2]

//   3
//  / \
// 1   4
//    /
//   2

// Output: [2,1,4,null,null,3]

//   2
//  / \
// 1   4
//    /
//   3
// Follow up:

// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?

// Tags: binary_search_tree, inorder

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
  void recoverTree(TreeNode *root) {
    vector<TreeNode *> values;
    inorder1(root, values);
    int ind1 = -1, ind2 = -1;
    if (values[0]->val > values[1]->val) {
      ind1 = 0;
      ind2 = 1;
    }
    for (int i = 1; i < values.size(); i++) {
      if (ind1 == -1 && values[i - 1]->val > values[i]->val) {
        ind1 = i - 1;
        ind2 = i;
      } else if (ind1 != -1 && values[i - 1]->val > values[i]->val) {
        ind2 = i;
      }
    }
    int tmp = values[ind1]->val;
    values[ind1]->val = values[ind2]->val;
    values[ind2]->val = tmp;
  }
  void inorder1(TreeNode *p, vector<TreeNode *> &values) {
    if (p) {
      inorder1(p->left, values);
      values.push_back(p);
      inorder1(p->right, values);
    }
  }
};
class SolutionMorrisInorderTraversal {
 public:
  void recoverTree(TreeNode *root) {
    TreeNode *cur, *pre;
    if (root == nullptr) {
      return;
    }
    cur = root;
    TreeNode *p1, *p2, *prev;
    p1 = p2 = prev = nullptr;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        handle(cur, prev, &p1, &p2);
        prev = cur;
        cur = cur->right;
      } else {
        pre = cur->left;
        while (pre->right != nullptr && pre->right != cur) {
          pre = pre->right;
        }
        if (pre->right == nullptr) {
          pre->right = cur;
          cur = cur->left;
        } else {
          pre->right = nullptr;
          handle(cur, prev, &p1, &p2);
          prev = cur;
          cur = cur->right;
        }
      }
    }
    int tmp = p1->val;
    p1->val = p2->val;
    p2->val = tmp;
  }
  void handle(TreeNode *cur, TreeNode *prev, TreeNode **p1, TreeNode **p2) {
    if (prev == nullptr) {
      return;
    }
    if (prev->val > cur->val) {
      if (*p1 == nullptr) {
        *p1 = prev;
        *p2 = cur;
      } else {
        *p2 = cur;
      }
    }
  }
};

TreeNode *constructTree(vector<long long> &a, int i) {
  if (i >= a.size() || a[i] == LONG_LONG_MIN) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(a[i]);
  root->left = constructTree(a, 2 * i + 1);
  root->right = constructTree(a, 2 * i + 2);
  return root;
}
void inorder(TreeNode *p) {
  if (p) {
    inorder(p->left);
    cout << p->val << " ";
    inorder(p->right);
  }
}
void solve() {
  vector<vector<long long>> tc = {{1, 3, LONG_LONG_MIN, LONG_LONG_MIN, 2}};
  SolutionMorrisInorderTraversal s;
  for (auto &i : tc) {
    TreeNode *root = constructTree(i, 0);
    s.recoverTree(root);
    inorder(root);
    cout << "\nDD\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
