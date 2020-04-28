// Jump Game

// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.

// Each element in the array represents your maximum jump length at that
// position.

// Determine if you are able to reach the last index.

// Example 1:

// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last
//              index.

// Tags: dynamic_programming

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& a) {
    int n = a.size();
    if (n == 0) {
      return true;
    }
    int ce = a[0];
    for (int i = 1; i < n - 1; i++) {
      if (ce < i) {
        break;
      }
      ce = max(ce, i + a[i]);
    }
    return ce >= n - 1;
  }
};
void solve() {
  vector<vector<int>> tc = {
      {2, 3, 1, 1, 4}, {3, 2, 1, 0, 4}, {0, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  Solution s;
  for (auto& i : tc) {
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    cout << boolalpha << s.canJump(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
