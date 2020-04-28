// Product of Array Except Self

// Given an array nums of n integers where n > 1,  return an array output such
// that output[i] is equal to the product of all the elements of nums except
// nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not
// count as extra space for the purpose of space complexity analysis.)

// Tags: math, miscellaneous

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& a) {
    int n = a.size();
    vector<int> ans(n);
    ans[0] = 1;
    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * a[i - 1];
    }
    int r = 1;
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = ans[i] * r;
      r *= a[i];
    }
    return ans;
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 3, 4}};
  Solution s;
  for (auto& i : tc) {
    vector<int> ans = s.productExceptSelf(i);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
