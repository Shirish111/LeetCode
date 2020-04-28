// Populating Next Right Pointers in Each Node II

// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no
// next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Example:

// Input:
// {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

// Output:
// {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

// Explanation: Given the above binary tree (Figure A), your function should
// populate each next pointer to point to its next right node, just like in
// Figure B.

// Note:

// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra
// space for this problem.

// Tags: miscellaneous, binary_tree, traversal

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() {}

  Node(int _val, Node* _left, Node* _right, Node* _next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};

class Solution {
 public:
  Node* connect(Node* root) {
    Node *pre = root, *cur = nullptr, *prev;
    while (pre) {
      cur = pre;
      pre = nullptr;
      prev = nullptr;
      while (cur) {
        if (prev) {
          if (cur->left) {
            prev->next = cur->left;
          } else if (cur->right) {
            prev->next = cur->right;
          }
        }
        if (cur->left && cur->right) {
          cur->left->next = cur->right;
        }
        setNode(&prev, cur->right, cur->left);
        if (pre == nullptr) {
          setNode(&pre, cur->left, cur->right);
        }
        cur = cur->next;
      }
    }
    return root;
  }
  void setNode(Node** p, Node* p1, Node* p2) {
    if (p1) {
      *p = p1;
    } else if (p2) {
      *p = p2;
    }
  }
};
Node* constructTree(vector<int>& a, int i) {
  if (i >= a.size() || a[i] == INT_MAX) {
    return nullptr;
  }
  Node* root = new Node(a[i], nullptr, nullptr, nullptr);
  root->left = constructTree(a, 2 * i + 1);
  root->right = constructTree(a, 2 * i + 2);
  return root;
}
void inorder(Node* p) {
  if (p) {
    inorder(p->left);
    cout << p->val << " ";
    if (p->next) {
      cout << "Next: " << p->next->val << " ";
    }
    inorder(p->right);
  }
}
void solve() {
  vector<vector<int>> tc = {{1, 2, 3, 4, INT_MAX, INT_MAX, 7, 8, 9, INT_MAX,
                             INT_MAX, INT_MAX, INT_MAX, 14, 15}};
  Solution s;
  for (auto& i : tc) {
    Node* root = constructTree(i, 0);
    inorder(root);
    cout << "\n";
    s.connect(root);
    inorder(root);
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
