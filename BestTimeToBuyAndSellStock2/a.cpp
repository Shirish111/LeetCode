// Best Time to Buy and Sell Stock II

// Say you have an array for which the ith element is the price of a given stock
// on day i.

// Design an algorithm to find the maximum profit. You may complete as many
// transactions as you like (i.e., buy one and sell one share of the stock
// multiple times).

// Note: You may not engage in multiple transactions at the same time (i.e., you
// must sell the stock before you buy again).

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
// 5-1 = 4.
//              Then buy on day 4 (price = 3) and sell on day 5 (price = 6),
//              profit = 6-3 = 3.
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

// Tags: dynamic_programming, interview
// Difficulty: Medium
// Important: Peak Valley graphical analysis
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& a) {
    int mx = 0;
    int n = a.size();
    for (int i = 1; i < n; i++) {
      mx += max(0, a[i] - a[i - 1]);
    }
    return mx;
  }
};

class Solution2 {
 public:
  int maxProfit(vector<int>& a) {
    int mx = 0;
    int peak, valley;
    int i = 0;
    int n = a.size();
    while (i < n) {
      while (i < n && a[i] >= a[i + 1]) {
        i++;
      }
      valley = a[i];
      while (i < n && a[i] <= a[i + 1]) {
        i++;
      }
      peak = a[i];
      mx += peak - valley;
      i++;
    }
    return mx;
  }
};

void solve() {
  vector<vector<int>> tc = {
      {7, 1, 5, 3, 6, 4}, {1, 2, 3, 4, 5}, {7, 6, 4, 3, 1}};
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
