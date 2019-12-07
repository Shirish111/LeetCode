// Maximum Product Subarray

// Given an integer array nums, find the contiguous subarray within an array
// (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define PB push_back
#define F0(I, N) for (ll I = 0; I < N; I++)
#define F1(I, N) for (ll I = 1; I <= N; I++)
#define F(I, X, N) for (ll I = X; I < N; I++)
#define R0(I, N) for (ll I = N - 1; I >= 0; I--)
#define R1(I, N) for (ll I = N; I > 0; I--)
#define R(I, X, N) for (ll I = N - 1; I >= X; I--)
#define A(X) X.begin(), X.end()

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    int mx, mn, r;
    r = mx = mn = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] < 0) {
        swap(mx, mn);
      }
      mx = max(nums[i], mx * nums[i]);
      mn = min(nums[i], mn * nums[i]);
      r = max(r, mx);
    }
    return r;
  }
};
void solve() {
  vector<vector<int>> tc = {{2, 3, -2, 4}, {2, 3, -2, 4, -1}};
  Solution s;
  for (auto& i : tc) {
    cout << s.maxProduct(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
