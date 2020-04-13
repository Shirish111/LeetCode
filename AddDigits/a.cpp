// Add Digits

// Given a non-negative integer num, repeatedly add all its digits until the
// result has only one digit.

// Example:

// Input: 38
// Output: 2
// Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
//              Since 2 has only one digit, return it.
// Follow up:
// Could you do it without any loop/recursion in O(1) runtime?

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int addDigits(int num) { return 1 + (num - 1) % 9; }
};

void solve() {
  vector<int> tc = {1, 2, 12, 18, 19, 21};
  Solution s;
  for (auto &i : tc) {
    cout << s.addDigits(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
