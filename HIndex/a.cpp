// H-Index

// Given an array of citations (each citation is a non-negative integer) of a
// researcher, write a function to compute the researcher's h-index.

// According to the definition of h-index on Wikipedia: "A scientist has index h
// if h of his/her N papers have at least h citations each, and the other N − h
// papers have no more than h citations each."

// Example:

// Input: citations = [3,0,6,1,5]
// Output: 3
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each
// of them had
//              received 3, 0, 6, 1, 5 citations respectively.
//              Since the researcher has 3 papers with at least 3 citations each
//              and the remaining two with no more than 3 citations each, her
//              h-index is 3.
// Note: If there are several possible values for h, the maximum one is taken as
// the h-index.

// Tags: dynamic_programming

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> freq(n + 1);
    for (auto& i : citations) {
      if (i >= n) {
        freq[n]++;
      } else {
        freq[i]++;
      }
    }
    int dp = 0;
    for (int i = n; i >= 0; --i) {
      dp += freq[i];
      if (dp >= i) {
        return i;
      }
    }
    return 0;
  }
};

void solve() {
  vector<vector<int>> tc = {{3, 0, 6, 1, 5}};
  Solution s;
  for (auto& i : tc) {
    cout << s.hIndex(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
