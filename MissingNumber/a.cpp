// Missing Number

// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
// the one that is missing from the array.

// Example 1:

// Input: [3,0,1]
// Output: 2
// Example 2:

// Input: [9,6,4,2,3,5,7,0,1]
// Output: 8
// Note:
// Your algorithm should run in linear runtime complexity. Could you implement
// it using only constant extra space complexity?

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    bool zero = false;
    int sm1 = 0;
    for (auto& i : nums) {
      if (i == 0) {
        zero = true;
      }
      sm1 += i;
    }
    if (!zero) {
      return 0;
    }
    int n = nums.size();
    return n * (n + 1) / 2 - sm1;
  }
};

void solve() {
  vector<vector<int>> tc = {{3, 0, 1}, {9, 6, 4, 2, 3, 5, 7, 0, 1}};
  Solution s;
  for (auto& i : tc) {
    cout << s.missingNumber(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
