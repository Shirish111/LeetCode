// Jump Game II

// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.

// Each element in the array represents your maximum jump length at that
// position.

// Your goal is to reach the last index in the minimum number of jumps.

// Example:

// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Note:

// You can assume that you can always reach the last index.

// Tags: dynamic_programming

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& a) {
    int cend = 0, cmax = 0, j = 0, n = a.size();
    for (int i = 0; i < n - 1; i++) {
      cmax = max(cmax, i + a[i]);
      if (cend == i) {
        j++;
        cend = cmax;
      }
    }
    return j;
  }
};
void solve() {
  vector<vector<int>> tc = {{2, 3, 1, 1, 4}};
  Solution s;
  for (auto& i : tc) {
    cout << s.jump(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
