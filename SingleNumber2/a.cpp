// Single Number II

// Given a non-empty array of integers, every element appears three times except
// for one, which appears exactly once. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you implement
// it without using extra memory?

// Example 1:

// Input: [2,2,3,2]
// Output: 3
// Example 2:

// Input: [0,1,0,1,0,1,99]
// Output: 99

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
  int singleNumber(vector<int>& a) {
    int x1, x2, mask;
    x1 = x2 = mask = 0;
    for (auto& i : a) {
      x2 ^= x1 & i;
      x1 ^= i;
      mask = ~(x1 & x2);
      x2 &= mask;
      x1 &= mask;
    }
    return x1;
  }
};
void solve() {
  vector<vector<int>> tc = {{2, 2, 3, 2}, {0, 1, 0, 1, 0, 1, 99}};
  Solution s;
  for (auto& i : tc) {
    cout << s.singleNumber(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
