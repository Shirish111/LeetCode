// Max Points on a Line

// Given n points on a 2D plane, find the maximum number of points that lie on
// the same straight line.

// Example 1:

// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o
// +------------->
// 0  1  2  3  4
// Example 2:

// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
// NOTE: input types have been changed on April 15, 2019. Please reset to
// default code definition to get new method signature.

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
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) {
      return n;
    }
    unordered_map<int, unordered_map<int, int>> same_slope;
    int ans = 0;
    int overlap, mx;
    for (int i = 0; i < n - 1; ++i) {
      overlap = mx = 0;
      same_slope.clear();
      for (int j = i + 1; j < n; ++j) {
        int xd = points[j][0] - points[i][0];
        int yd = points[j][1] - points[i][1];
        if (xd == 0 && yd == 0) {
          overlap++;
          continue;
        }
        int gcd_ = gcd(xd, yd);
        xd /= gcd_;
        yd /= gcd_;

        mx = max(mx, ++same_slope[xd][yd]);
      }
      ans = max(ans, mx + overlap);
    }
    return ans + 1;
  }
  int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }
    while (b != 0) {
      int tmp = b;
      b = a % b;
      a = tmp;
    }
    return a;
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {
      {{1, 1}, {2, 2}, {3, 3}},
      {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}},
      {{2, 3}, {3, 3}, {-5, 3}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.maxPoints(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
