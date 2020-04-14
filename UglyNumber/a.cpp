// Ugly Number

// Write a program to check whether a given number is an ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isUgly(int num) {
    if (num == 0) {
      return false;
    }
    vector<int> d = {2, 3, 5};
    for (auto &i : d) {
      while (num % i == 0) {
        num /= i;
      }
    }
    return num == 1;
  }
};

void solve() {
  vector<int> tc = {6, 8, 14, -2147483648};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isUgly(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
