// Best Time to Buy and Sell Stock

// Say you have an array for which the ith element is the price of a given stock
// on day i.

// If you were only permitted to complete at most one transaction (i.e., buy one
// and sell one share of the stock), design an algorithm to find the maximum
// profit.

// Note that you cannot sell a stock before you buy one.

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
// 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying
//              price.
// Example 2:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

// Tags: dynamic_programming, interview
// Difficulty: Easy
// Important: Left to right parse array and keep the value of minimum seen so
// far
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& a) {
    int mx = 0;
    int n = a.size();
    if (n == 0) {
      return 0;
    }
    int mn = a[0];
    for (int i = 0; i < n; i++) {
      mn = min(mn, a[i]);
      mx = max(mx, a[i] - mn);
    }
    return mx;
  }
};
void solve() {
  vector<vector<int>> tc = {{7, 1, 5, 3, 6, 4}, {7, 6, 4, 3, 1}};
  Solution s;
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
