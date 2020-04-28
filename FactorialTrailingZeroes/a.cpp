// Factorial Trailing Zeroes

// Given an integer n, return the number of trailing zeroes in n!.

// Example 1:

// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Note: Your solution should be in logarithmic time complexity.

// Tags: math

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trailingZeroes(int n) {
    int cnt = 0;
    while (n) {
      cnt += n / 5;
      n /= 5;
    }
    return cnt;
  }
};
void solve() {
  vector<int> tc = {3, 5, 10, 15, 22};
  Solution s;
  for (auto &i : tc) {
    cout << s.trailingZeroes(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
