// Binary Tree Inorder Traversal

// Given a binary tree, return the inorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,3,2]
// Follow up: Recursive solution is trivial, could you do it iteratively?

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

// Using Recursion
class SolutionR {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    inorderTraversal(root, ans);
    return ans;
  }
  void inorderTraversal(TreeNode *p, vector<int> &ans) {
    if (p) {
      inorderTraversal(p->left, ans);
      ans.push_back(p->val);
      inorderTraversal(p->right, ans);
    }
  }
  void preorderTraversal(TreeNode *p, vector<int> &ans) {
    if (p) {
      ans.push_back(p->val);
      preorderTraversal(p->left, ans);
      preorderTraversal(p->right, ans);
    }
  }
  void postorderTraversal(TreeNode *p, vector<int> &ans) {
    if (p) {
      postorderTraversal(p->left, ans);
      postorderTraversal(p->right, ans);
      ans.push_back(p->val);
    }
  }
};
// Using Iterative Approach
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *p) {
    vector<int> ans;
    if (!p) {
      return ans;
    }
    stack<TreeNode *> stk;
    while (p != nullptr || !stk.empty()) {
      while (p != nullptr) {
        stk.push(p);
        p = p->left;
      }
      p = stk.top();
      stk.pop();
      ans.push_back(p->val);
      p = p->right;
    }
    return ans;
  }
  vector<int> preorderTraversal(TreeNode *p) {
    vector<int> ans;
    if (!p) {
      return ans;
    }
    stack<TreeNode *> stk;
    stk.push(p);
    while (!stk.empty()) {
      p = stk.top();
      stk.pop();
      ans.push_back(p->val);
      if (p->right) {
        stk.push(p->right);
      }
      if (p->left) {
        stk.push(p->left);
      }
    }
    return ans;
  }
  // Using Two Stacks
  vector<int> postorderTraversal(TreeNode *p) {
    vector<int> ans;
    stack<TreeNode *> s2;
    stack<TreeNode *> s1;
    if (!p) {
      return ans;
    }
    s1.push(p);
    while (!s1.empty()) {
      p = s1.top();
      s1.pop();
      s2.push(p);
      if (p->left) {
        s1.push(p->left);
      }
      if (p->right) {
        s1.push(p->right);
      }
    }
    while (!s2.empty()) {
      ans.push_back(s2.top()->val);
      s2.pop();
    }
    return ans;
  }
};
void solve() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  Solution s;
  vector<int> v = s.postorderTraversal(root);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << "\n";
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
