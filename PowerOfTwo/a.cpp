// Power of Two

// Given an integer, write a function to determine if it is a power of two.

// Example 1:

// Input: 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: 218
// Output: false

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    return (n & (n - 1)) == 0;
  }
};
void solve() {
  vector<int> tc = {1, 16, 218};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isPowerOfTwo(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
