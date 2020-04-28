// Bitwise AND of Numbers Range

// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND
// of all numbers in this range, inclusive.

// Example 1:

// Input: [5,7]
// Output: 4
// Example 2:

// Input: [0,1]
// Output: 0

// Tags: bit_manipulation, bitwise_and, interview
// Difficulty: Medium
// Important:
// Bitwise AND of a range can be solved as
// If n > m => the LSB will be 0
// Now the subproblem is to solve (n >> 1) and (m >> 1)
// Do this until n == m
// The answer is m << movefactor
// Status: Done

#include <bits/stdc++.h>
using namespace std;

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
