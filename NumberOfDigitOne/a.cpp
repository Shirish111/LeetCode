// Number of Digit One

// Given an integer n, count the total number of digit 1 appearing in all
// non-negative integers less than or equal to n.

// Example:

// Input: 13
// Output: 6
// Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

// Tags: miscellaneous, number

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    int ones = 0;
    for (long long m = 1; m <= n; m *= 10) {
      int a = n / m, b = n % m;
      ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
  }
};
void solve() {
  vector<int> tc = {13, 1};
  Solution s;
  for (auto &i : tc) {
    cout << s.countDigitOne(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
