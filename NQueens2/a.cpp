// N-Queens II

// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens
// puzzle.

// Example:

// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown
// below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

// Tags: back_tracking, recursion

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int ans;
  vector<array<int, 2>> pos;
  int totalNQueens(int n) {
    ans = 0;
    backtrack(n, 0);
    return ans;
  }
  void backtrack(int n, int row) {
    if (row == n) {
      ans++;
      return;
    }
    for (int col = 0; col < n; col++) {
      if (isValid(row, col)) {
        pos.push_back({row, col});
        backtrack(n, row + 1);
        pos.pop_back();
      }
    }
  }
  bool isValid(int row, int col) {
    for (auto& i : pos) {
      // Check Horizontal
      if (i[0] - row == 0 || i[1] - col == 0) {
        return false;
      }
      // Diagnonal
      if (abs(i[0] - row) == abs(i[1] - col)) {
        return false;
      }
    }
    return true;
  }
};
void solve() {
  vector<int> tc = {4, 5};
  for (auto& i : tc) {
    Solution s;
    int ans = s.totalNQueens(i);
    cout << ans << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
