// Bitwise AND of Numbers Range

// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
// of all numbers in this range, inclusive.

// Example 1:

// Input: [5,7]
// Output: 4
// Example 2:

// Input: [0,1]
// Output: 0

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
  int rangeBitwiseAnd(int m, int n) {
    int moveFactor = 0;
    while (m != n) {
      m >>= 1;
      n >>= 1;
      moveFactor++;
    }
    return m << moveFactor;
  }
};
void solve() {
  vector<pair<int, int>> tc = {{5, 7}, {0, 1}};
  Solution s;
  for (auto &i : tc) {
    cout << s.rangeBitwiseAnd(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
