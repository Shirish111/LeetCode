// Maximum Subarray

// Given an integer array nums, find the contiguous subarray (containing at
// least one number) which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:

// If you have figured out the O(n) solution, try coding another solution using
// the divide and conquer approach, which is more subtle.

// Tags: kadane, dynamic_programming

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& a) {
    int n = a.size(), cur_sum = a[0], max_sum = a[0];
    for (int i = 1; i < n; i++) {
      cur_sum = max(a[i], cur_sum + a[i]);
      max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
  }
};
void solve() {
  vector<vector<int>> tc = {{-2, 1, -3, 4, -1, 2, 1, -5, 4}};
  Solution s;
  for (auto& i : tc) {
    cout << s.maxSubArray(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
