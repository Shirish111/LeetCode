// 3Sum Closest

// Given an array nums of n integers and an integer target, find three integers
// in nums such that the sum is closest to target. Return the sum of the three
// integers. You may assume that each input would have exactly one solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Tags: sorting, two_pointers
// Difficulty: Medium
// Important: Skipping elements
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& a, int target) {
    int diff, sm, n = a.size(), fp, bp, sum = 0, mindiff = INT_MAX;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2;) {
      fp = i + 1;
      bp = n - 1;
      while (fp < bp) {
        sm = a[i] + a[fp] + a[bp];
        diff = abs(sm - target);
        if (diff == 0) {
          return 0;
        }
        if (diff < mindiff) {
          mindiff = diff;
          sum = sm;
        }
        if (sm < target) {
          fp++;
        } else {
          bp--;
        }
      }
      i++;
      while (i < n && a[i] == a[i - 1]) i++;
    }
    return sum;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{-1, 2, 1, -4}, 1}};
  Solution s;
  for (auto& i : tc) {
    cout << s.threeSumClosest(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
