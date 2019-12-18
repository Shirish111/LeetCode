// House Robber

// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed, the only constraint stopping you
// from robbing each of them is that adjacent houses have security system
// connected and it will automatically contact the police if two adjacent houses
// were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of
// each house, determine the maximum amount of money you can rob tonight without
// alerting the police.

// Example 1:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5
// (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.

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
  vector<int> dp;
  int rob(vector<int> &a) {
    int n = a.size();
    if (n == 0) {
      return 0;
    }
    dp.assign(n, -1);
    return rob(a, n - 1);
  }
  int rob(vector<int> &a, int i) {
    if (i < 0) {
      return 0;
    }
    if (dp[i] != -1) {
      return dp[i];
    }
    dp[i] = max(a[i] + rob(a, i - 2), rob(a, i - 1));
    return dp[i];
  }
};
void solve() {}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
