// Unique Binary Search Trees

// Given n, how many structurally unique BST's (binary search trees) that store
// values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

// Tags: binary_search_tree, recursion, catalan_number

#include <bits/stdc++.h>
using namespace std;

class SolutionR {
 public:
  int numTrees(int n) {
    if (n <= 1) {
      return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += numTrees(i) * numTrees(n - i - 1);
    }
    return ans;
  }
};
class Solution {
 public:
  int numTrees(int n) {
    vector<int> catalan(n + 1);
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++) {
      catalan[i] = 0;
      for (int j = 0; j < i; j++) {
        catalan[i] += catalan[j] * catalan[i - j - 1];
      }
    }
    return catalan[n];
  }
};
void solve() {
  vector<int> tc = {1, 2, 3, 4, 5};
  Solution s;
  for (auto &i : tc) {
    cout << i << " " << s.numTrees(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
