//  N-Queens

//  The n-queens puzzle is the problem of placing n queens on an n×n chessboard
//  such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space
// respectively.

// Example:

// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as
// shown above.

// Tags: back_tracking, recursion

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> ans;
  vector<array<int, 2>> pos;
  vector<vector<string>> solveNQueens(int n) {
    vector<string> b(n, string(n, '.'));
    backtrack(b, n, 0);
    return ans;
  }
  void backtrack(vector<string>& b, int n, int row) {
    if (row == n) {
      ans.push_back(b);
      return;
    }
    for (int col = 0; col < n; col++) {
      if (isValid(row, col)) {
        pos.push_back({row, col});
        b[row][col] = 'Q';
        backtrack(b, n, row + 1);
        b[row][col] = '.';
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
    vector<vector<string>> ans = s.solveNQueens(i);
    for (auto& j : ans) {
      for (auto& k : j) {
        cout << k << "\n";
      }
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
