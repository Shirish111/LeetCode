// Container With Most Water

// Given n non-negative integers a1, a2, ..., an , where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
// of line i is at (i, ai) and (i, 0). Find two lines, which together with
// x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
// this case, the max area of water (blue section) the container can contain
// is 49.

// Example:

// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

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
  int maxArea(vector<int>& h) {
    int mx = 0;
    int n = h.size();
    int fp = 0, bp = n - 1;
    while (fp < bp) {
      mx = max(mx, min(h[fp], h[bp]) * (bp - fp));
      if (h[fp] < h[bp]) {
        fp++;
      } else {
        bp--;
      }
    }
    return mx;
  }
};
void solve() {}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
