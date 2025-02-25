// Pascal's Triangle

// Given a non-negative integer numRows, generate the first numRows of Pascal's
// triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly
// above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

// Tags: combinatorics, pascals_triangle

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    int i = 1;
    vector<vector<int>> res;
    if (numRows == 0) {
      return res;
    }
    res.push_back({1});
    while (i < numRows) {
      vector<int> a(i + 1);
      a[0] = 1;
      for (int j = 1; j < i; j++) {
        a[j] = res[i - 1][j - 1] + res[i - 1][j];
      }
      a[i] = 1;
      res.push_back(a);
      i++;
    }
    return res;
  }
};
void solve() {
  vector<int> tc = {1, 2, 3, 4, 5};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> ans = s.generate(i);
    for (auto &j : ans) {
      copy(j.begin(), j.end(), ostream_iterator<int>(cout, " "));
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
