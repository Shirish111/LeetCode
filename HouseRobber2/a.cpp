// House Robber II

// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed. All houses at this place are
// arranged in a circle. That means the first house is the neighbor of the last
// one. Meanwhile, adjacent houses have security system connected and it will
// automatically contact the police if two adjacent houses were broken into on
// the same night.

// Given a list of non-negative integers representing the amount of money of
// each house, determine the maximum amount of money you can rob tonight without
// alerting the police.

// Example 1:

// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
// 2),
//              because they are adjacent houses.
// Example 2:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.

// Tags: dynamic_programming, recursion

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& a) {
    int n = a.size();
    if (n == 1) {
      return a[0];
    }
    return max(f(a, 0, n - 2), f(a, 1, n - 1));
  }
  int f(vector<int>& a, int beg, int end) {
    int p1, p2;
    p1 = p2 = 0;
    for (int i = beg; i <= end; ++i) {
      int tmp = p1;
      p1 = max(a[i] + p2, p1);
      p2 = tmp;
    }
    return p1;
  }
};
void solve() {
  vector<vector<int>> tc = {{2, 3, 2}, {1, 2, 3, 1}, {1}};
  Solution s;
  for (auto& i : tc) {
    cout << s.rob(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
