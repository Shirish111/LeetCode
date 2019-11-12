// Sqrt(x)

// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a
// non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and
// only the integer part of the result is returned.

// Example 1:

// Input: 4
// Output: 2
// Example 2:

// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since
//              the decimal part is truncated, 2 is returned.

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

// Using Binary Search
class SolutionBin {
 public:
  int mySqrt(int x) {
    long long l = 0, h = x;
    while (l < h) {
      long long mid = (l + h + 1) / 2;
      if (mid * mid > x) {
        h = mid - 1;
      } else {
        l = mid;
      }
    }
    return l;
  }
};
// Using Newton's method
class Solution {
 public:
  int mySqrt(int x) {
    long long r = x;
    while (r * r > x) {
      r = (r + x / r) / 2;
    }
    return r;
  }
};
void solve() {
  vector<int> tc = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2147395600};
  Solution s;
  for (auto &i : tc) {
    cout << "Sqrt of (" << i << ") = " << s.mySqrt(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
