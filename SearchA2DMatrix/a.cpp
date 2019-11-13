// Search a 2D Matrix

// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the
// previous row. Example 1:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:

// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

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
  bool searchMatrix(vector<vector<int>>& a, int target) {
    int m = a.size();
    if (m == 0) {
      return false;
    }
    int n = a[0].size();
    int l = 0, h = m * n - 1;
    while (l <= h) {
      int mid = l + (h - l) / 2;
      int num = a[mid / n][mid % n];
      if (num == target) {
        return true;
      } else if (num < target) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
    return false;
  }
};
void solve() {
  vector<pair<vector<vector<int>>, int>> tc = {
      {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 3},
      {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, 13},
      {{{1, 1}}, 1}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.searchMatrix(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
