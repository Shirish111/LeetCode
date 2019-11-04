// Sudoku Solver

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
// sub-boxes of the grid. Empty cells are indicated by the character '.'.

// A sudoku puzzle...

// ...and its solution numbers marked in red.

// Note:

// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique
// solution. The given board size is always 9x9.

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

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { solve(board); }
  bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          for (char c = '0'; c <= '9'; c++) {
            if (isValid(board, i, j, c)) {
              board[i][j] = c;
              if (solve(board)) {
                return true;
              } else {
                board[i][j] = '.';
              }
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
      if (board[i][col] != '.' && board[i][col] == c) return false;
      if (board[row][i] != '.' && board[row][i] == c) return false;
      char k = board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3];
      if (k != '.' && k == c) return false;
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
  solution.solveSudoku(b);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << b[i][j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
