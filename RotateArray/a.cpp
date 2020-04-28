// Rotate Array

// Given an array, rotate the array to the right by k steps, where k is
// non-negative.

// Example 1:

// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: [-1,-100,3,99] and k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
// Note:

// Try to come up as many solutions as you can, there are at least 3 different
// ways to solve this problem. Could you do it in-place with O(1) extra space?

// Tags: array, rotate

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{1, 2, 3, 4, 5, 6, 7}, 3},
                                       {{-1, -100, 3, 99}, 2}};
  Solution s;
  for (auto &i : tc) {
    cout << "Before: ";
    copy(i.first.begin(), i.first.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    s.rotate(i.first, i.second);
    cout << "After: ";
    copy(i.first.begin(), i.first.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
