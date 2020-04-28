// Power of Three

// Given an integer, write a function to determine if it is a power of three.

// Example 1:

// Input: 27
// Output: true
// Example 2:

// Input: 0
// Output: false
// Example 3:

// Input: 9
// Output: true
// Example 4:

// Input: 45
// Output: false
// Follow up:
// Could you do it without using any loop / recursion?
// Tags: math
// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

// Using Binary Search
class Solution1 {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) {
      return false;
    }
    long long n1 = n;
    long long l = 0, h = 20, p, mid;
    while (l <= h) {
      mid = (l + h) / 2;
      p = pow(3, mid);
      if (p == n1) {
        return true;
      }
      if (p > n1) {
        h = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return false;
  }
};

// Using continuous division
class Solution2 {
 public:
  bool isPowerOfThree(int n) {
    while (n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  }
};

// Using O(1) Solution 3^19 = 1162261467
class Solution {
 public:
  bool isPowerOfThree(int n) { return n > 0 && 1162261467 % n == 0; }
};

void solve() {
  vector<int> tc = {3, -3};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isPowerOfThree(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
