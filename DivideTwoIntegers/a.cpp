// // Divide Two Integers

// Given two integers dividend and divisor, divide two integers without using
// multiplication, division and mod operator.

// Return the quotient after dividing dividend by divisor.

// The integer division should truncate toward zero.

// Example 1:

// Input: dividend = 10, divisor = 3
// Output: 3
// Example 2:

// Input: dividend = 7, divisor = -3
// Output: -2
// Note:

// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers
// within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
// this problem, assume that your function returns 231 − 1 when the division
// result overflows.

// Tags: bit_manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int divide(int dv, int d) {
    if (dv == INT_MIN && d == -1) {
      return INT_MAX;
    }
    int sign = dv > 0 ^ d > 0 ? -1 : 1;
    long dvd = labs(dv), dvs = labs(d), q = 0;
    while (dvd >= dvs) {
      int bs = 0;
      while (dvd >= (dvs << bs)) {
        bs++;
      }
      bs--;
      q += (1 << bs);
      dvd -= (dvs << bs);
    }
    return sign * q;
  }
};
void solve() {
  vector<pair<int, int>> tc = {{17, 3},      {7, -3},       {10, 3},
                               {INT_MAX, 1}, {INT_MAX, -1}, {INT_MIN, 1},
                               {INT_MIN, -1}};
  int nt = tc.size();
  Solution solution;
  for (int i = 0; i < nt; i++) {
    cout << tc[i].first << " " << tc[i].second << " "
         << solution.divide(tc[i].first, tc[i].second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
