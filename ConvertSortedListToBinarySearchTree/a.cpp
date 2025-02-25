// Convert Sorted List to Binary Search Tree

// Given a singly linked list where elements are sorted in ascending order,
// convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.

// Example:

// Given the sorted linked list: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following
// height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5

// Tags: binary_search_tree, list

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    vector<int> a = list_to_vector(head);
    return buildTree(a, 0, a.size() - 1);
  }
  TreeNode *buildTree(vector<int> &a, int l, int h) {
    if (l > h) {
      return nullptr;
    }
    int mid = (l + h) / 2;
    TreeNode *root = new TreeNode(a[mid]);
    root->left = buildTree(a, l, mid - 1);
    root->right = buildTree(a, mid + 1, h);
    return root;
  }
  vector<int> list_to_vector(ListNode *head) {
    vector<int> a;
    while (head) {
      a.push_back(head->val);
      head = head->next;
    }
    return a;
  }
};
void solve() {}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
