// Unique Binary Search Trees II

// Given an integer n, generate all structurally unique BST's (binary search
// trees) that store values 1 ... n.

// Example:

// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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

class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> ans;
    if (n == 0) {
      return ans;
    }
    return generateTrees(1, n);
  }
  vector<TreeNode *> generateTrees(int start, int end) {
    vector<TreeNode *> tree_array;
    if (start > end) {
      tree_array.push_back(nullptr);
    }
    for (int i = start; i <= end; i++) {
      vector<TreeNode *> left_subtrees = generateTrees(start, i - 1);
      vector<TreeNode *> right_subtrees = generateTrees(i + 1, end);
      for (auto &left : left_subtrees) {
        for (auto &right : right_subtrees) {
          TreeNode *root = new TreeNode(i);
          root->left = left;
          root->right = right;
          tree_array.push_back(root);
        }
      }
    }
    return tree_array;
  }
};
void preorder(TreeNode *t) {
  if (t) {
    cout << t->val << " ";
    preorder(t->left);
    preorder(t->right);
  } else {
    cout << "nullptr"
         << " ";
  }
}
void solve() {
  vector<int> tc = {3};
  Solution s;
  for (auto &i : tc) {
    vector<TreeNode *> trees = s.generateTrees(i);
    for (auto &j : trees) {
      preorder(j);
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
