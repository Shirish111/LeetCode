// Candy

// There are N children standing in a line. Each child is assigned a rating
// value.

// You are giving candies to these children subjected to the following
// requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Example 1:

// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1,
// 2 candies respectively. Example 2:

// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2,
// 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two
//              conditions.

// Tags: two_sweeps
// Difficulty: Easy
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
        candies[i] = candies[i + 1] + 1;
      }
    }
    return accumulate(candies.begin(), candies.end(), 0);
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 3}, {1, 2, 2}, {1, 2, 1, 0}};
  Solution s;
  for (auto& i : tc) {
    cout << s.candy(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
