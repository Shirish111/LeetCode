// Best Time to Buy and Sell Stock IV

// Say you have an array for which the i-th element is the price of a given
// stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k
// transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must
// sell the stock before you buy again).

// Example 1:

// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
// 4-2 = 2. Example 2:

// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
// 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
//              profit = 3-0 = 3.

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
  int maxProfit(int K, vector<int> &prices) {
    int n = prices.size();
    if (n == 0) {
      return 0;
    }
    if (K >= n / 2) {
      return quickSolve(prices, n);
    }
    vector<int> dp(K + 1);
    vector<int> mn(K + 1, prices[0]);
    for (int i = 0; i < n; ++i) {
      for (int k = 1; k <= K; ++k) {
        mn[k] = min(mn[k], prices[i] - dp[k - 1]);
        dp[k] = max(dp[k], prices[i] - mn[k]);
      }
    }
    return dp[K];
  }
  int quickSolve(vector<int> &prices, int n) {
    int sm = 0;
    for (int i = 1; i < n; ++i) {
      if (prices[i] > prices[i - 1]) {
        sm += prices[i] - prices[i - 1];
      }
    }
    return sm;
  }
};
void solve() {
  vector<pair<int, vector<int>>> tc = {{2, {2, 4, 1}}, {2, {3, 2, 6, 5, 0, 3}}};
  Solution s;
  for (auto &i : tc) {
    cout << s.maxProfit(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
