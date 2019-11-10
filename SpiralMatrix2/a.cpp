// Spiral Matrix II

// Given a positive integer n, generate a square matrix filled with elements
// from 1 to n2 in spiral order.

// Example:

// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans;
    if (n == 0) {
      return ans;
    }
    ans.resize(n, vector<int>(n));
    int cnt = 1;
    int cmin = 0, cmax = n - 1, rmin = 0, rmax = n - 1;
    while (cmin <= cmax && rmin <= rmax) {
      for (int i = cmin; i <= cmax; i++) {
        ans[rmin][i] = cnt++;
      }
      for (int i = rmin + 1; i <= rmax; i++) {
        ans[i][cmax] = cnt++;
      }
      if (rmin < rmax) {
        for (int i = cmax - 1; i >= cmin; i--) {
          ans[rmax][i] = cnt++;
        }
      }
      if (cmin < cmax) {
        for (int i = rmax - 1; i > rmin; i--) {
          ans[i][cmin] = cnt++;
        }
      }
      cmin++;
      rmin++;
      cmax--;
      rmax--;
    }
    return ans;
  }
};
void solve() {
  vector<int> tc = {0, 1, 2, 3};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> a = s.generateMatrix(i);
    for (auto &j : a) {
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
