// Rotate Image

// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Note:

// You have to rotate the image in-place, which means you have to modify the
// input 2D matrix directly. DO NOT allocate another 2D matrix and do the
// rotation.

// Example 1:

// Given input matrix =
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],

// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
// Example 2:

// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ],

// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]

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
  void rotate(vector<vector<int>> &mat) {
    int n = mat.size();
    reverse(mat.begin(), mat.end());
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(mat[i][j], mat[j][i]);
      }
    }
  }
};
class MatrixHelper {
 public:
  void print_matrix(vector<vector<int>> &mat, int n) {
    print_matrix(mat, n, n);
  }
  void print_matrix(vector<vector<int>> &mat, int n, int m) {
    for (auto &i : mat) {
      for (auto &j : i) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {
      {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}};
  Solution s;
  MatrixHelper mh;
  for (auto &i : tc) {
    s.rotate(i);
    mh.print_matrix(i, i.size());
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
