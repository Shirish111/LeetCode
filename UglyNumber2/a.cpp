// Ugly Number II

// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
// ugly numbers. Note:

// 1 is typically treated as an ugly number.
// n does not exceed 1690.

// Tags: miscellaneous, primes

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    if (n <= 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    vector<int> k(n);
    k[0] = 1;
    int t2, t3, t5;
    t2 = t3 = t5 = 0;
    for (int i = 1; i < n; ++i) {
      k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
      if (k[i] == k[t2] * 2) {
        t2++;
      }
      if (k[i] == k[t3] * 3) {
        t3++;
      }
      if (k[i] == k[t5] * 5) {
        t5++;
      }
    }
    return k[n - 1];
  }
};

void solve() {
  vector<int> tc = {10};
  Solution s;
  for (auto &i : tc) {
    cout << s.nthUglyNumber(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
