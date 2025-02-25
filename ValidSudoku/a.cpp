// Valid Sudoku

// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
// validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
// repetition.

// A partially filled sudoku which is valid.

// The Sudoku board could be partially filled, where empty cells are filled with
// the character '.'.

// Example 1:

// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
// Example 2:

// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner
// being
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
//     invalid.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily
// solvable. Only the filled cells need to be validated according to the
// mentioned rules. The given board contain only digits 1-9 and the character
// '.'. The given board size is always 9x9.

// Tags: hashing, sudoku

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& b) {
    bool row[9][9] = {}, col[9][9] = {}, sec[9][9] = {};
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (b[i][j] != '.') {
          int num = b[i][j] - '1', k = (i / 3) * 3 + j / 3;
          if (row[i][num] || col[j][num] || sec[k][num]) {
            return false;
          }
          row[i][num] = col[j][num] = sec[k][num] = true;
        }
      }
    }
    return true;
  }
};
void solve() {
  vector<vector<char>> b = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  Solution solution;
  cout << boolalpha << solution.isValidSudoku(b) << "\n";
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
