// // Pow(x, n)

// Implement pow(x, n), which calculates x raised to the power n (xn).

// Example 1:

// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:

// Input: 2.10000, 3
// Output: 9.26100
// Example 3:

// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
// Note:

// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−231, 231 − 1]

// Tags: binary_search

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double myPow(double x, int n1) {
    double ans = 1;
    bool sn = n1 < 0;
    long long n = abs((long long)n1);
    while (n) {
      if (n & 1) {
        ans = ans * x;
      }
      x = x * x;
      n >>= 1;
    }
    return sn ? 1 / ans : ans;
  }
};
void solve() {
  vector<pair<double, int>> tc = {{2, 10}, {2.1, 3}, {2, -2}, {-2, 2}, {-2, 3}};
  Solution s;
  for (auto &i : tc) {
    cout << i.first << " " << i.second << " " << s.myPow(i.first, i.second)
         << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
