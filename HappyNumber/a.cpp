// Happy Number

// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with
// any positive integer, replace the number by the sum of the squares of its
// digits, and repeat the process until the number equals 1 (where it will
// stay), or it loops endlessly in a cycle which does not include 1. Those
// numbers for which this process ends in 1 are happy numbers.

// Example:

// Input: 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int squares[10];
  bool isHappy(int n) {
    if (n == 1) {
      return true;
    }
    unordered_set<int> s;
    for (int i = 0; i < 10; ++i) {
      squares[i] = i * i;
    }
    while (n != 1) {
      if (s.find(n) != s.end()) {
        return false;
      }
      s.insert(n);
      n = calc(n);
    }
    return true;
  }
  int calc(int num) {
    string s = to_string(num);
    num = 0;
    for (auto &i : s) {
      num += squares[i - '0'];
    }
    return num;
  }
};
void solve() {
  vector<int> tc = {19};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isHappy(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
