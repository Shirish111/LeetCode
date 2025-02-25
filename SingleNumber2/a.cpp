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

// Tags: bit_manipulation, miscellaneous

#include <bits/stdc++.h>
using namespace std;

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
