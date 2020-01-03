// Rectangle Area

// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as
// shown in the figure.

// Rectangle Area

// Example:

// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
// Output: 45
// Note:

// Assume that the total area is never beyond the maximum possible value of int.

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
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    long long left = max(A, E), right = max((long long)min(C, G), left);
    long long bottom = max(B, F), top = max((long long)min(D, H), bottom);
    return (long long)(C - A) * (long long)(D - B) +
           (long long)(G - E) * (long long)(H - F) -
           (right - left) * (top - bottom);
  }
};
void solve() {
  struct Q {
    int A, B, C, D, E, F, G, H;
  };
  vector<Q> tc = {Q{-3, 0, 3, 4, 0, -1, 9, 2}};
  Solution s;
  for (auto &i : tc) {
    cout << s.computeArea(i.A, i.B, i.C, i.D, i.E, i.F, i.G, i.H) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
