// Best Time to Buy and Sell Stock III

// Say you have an array for which the ith element is the price of a given stock
// on day i.

// Design an algorithm to find the maximum profit. You may complete at most two
// transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you
// must sell the stock before you buy again).

// Example 1:

// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
// 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4),
//              profit = 4-1 = 3.
// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
// 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them
//              later, as you are engaging multiple transactions at the same
//              time. You must sell before buying again.
// Example 3:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
// Important:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/135704/Detail-explanation-of-DP-solution
// Tags: dynamic_programming, interview

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& a) {
    int hold1, hold2;
    hold1 = hold2 = INT_MIN;
    int release1, release2;
    release1 = release2 = 0;
    for (auto& i : a) {
      release2 = max(release2, hold2 + i);
      hold2 = max(hold2, release1 - i);
      release1 = max(release1, hold1 + i);
      hold1 = max(hold1, -i);
    }
    return release2;
  }
};
class SolutionDP {
 public:
  int maxProfit(vector<int>& prices) {
    int num_transactions = 2;
    int n = prices.size();
    if (n == 0) {
      return 0;
    }
    vector<int> dp(num_transactions + 1);
    vector<int> mn(num_transactions + 1, prices[0]);
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= num_transactions; k++) {
        mn[k] = min(mn[k], prices[j - 1] - dp[k - 1]);
        dp[k] = max(dp[k], prices[j - 1] - mn[k]);
      }
    }
    return dp[num_transactions];
  }
};

// For reference
// int MaxProfitDp(int[] prices) {
//   if (prices.Length == 0) return 0;
//   var dp = new int[3, prices.Length];
//   for (int k = 1; k <= 2; k++) {
//     for (int i = 1; i < prices.Length; i++) {
//       int min = prices[0];
//       for (int j = 1; j <= i; j++)
//         min = Math.Min(min, prices[j] - dp[k - 1, j - 1]);
//       dp[k, i] = Math.Max(dp[k, i - 1], prices[i] - min);
//     }
//   }

//   return dp[2, prices.Length - 1];
// }

void solve() {
  vector<vector<int>> tc = {
      {7, 1, 5, 3, 6, 4}, {1, 2, 3, 4, 5}, {7, 6, 4, 3, 1}};
  SolutionDP s;
  for (auto& i : tc) {
    cout << s.maxProfit(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
