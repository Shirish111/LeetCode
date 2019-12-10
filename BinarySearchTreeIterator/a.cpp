// Binary Search Tree Iterator

// Implement an iterator over a binary search tree (BST). Your iterator will be
// initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Example:

// BSTIterator iterator = new BSTIterator(root);
// iterator.next();    // return 3
// iterator.next();    // return 7
// iterator.hasNext(); // return true
// iterator.next();    // return 9
// iterator.hasNext(); // return true
// iterator.next();    // return 15
// iterator.hasNext(); // return true
// iterator.next();    // return 20
// iterator.hasNext(); // return false

// Note:

// next() and hasNext() should run in average O(1) time and uses O(h) memory,
// where h is the height of the tree. You may assume that next() call will
// always be valid, that is, there will be at least a next smallest number in
// the BST when next() is called.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define PB push_back
#define F0(I, N) for (ll I = 0; I < N; I++)
#define F1(I, N) for (ll I = 1; I <= N; I++)
#define F(I, X, N) for (ll I = X; I < N; I++)
#define R0(I, N) for (ll I = N - 1; I >= 0; I--)
#define R1(I, N) for (ll I = N; I > 0; I--)
#define R(I, X, N) for (ll I = N - 1; I >= X; I--)
#define A(X) X.begin(), X.end()

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
  vector<int> sorted_values;
  int cur;
  void inorder(TreeNode *p) {
    if (p) {
      inorder(p->left);
      sorted_values.push_back(p->val);
      inorder(p->right);
    }
  }

 public:
  BSTIterator(TreeNode *root) {
    cur = -1;
    inorder(root);
  }

  /** @return the next smallest number */
  int next() { return sorted_values.at(++cur); }

  /** @return whether we have a next smallest number */
  bool hasNext() { return cur != sorted_values.size() - 1; }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
void solve() {}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
