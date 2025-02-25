// Search Insert Position

// Given a sorted array and a target value, return the index if the target is
// found. If not, return the index where it would be if it were inserted in
// order.

// You may assume no duplicates in the array.

// Example 1:

// Input: [1,3,5,6], 5
// Output: 2
// Example 2:

// Input: [1,3,5,6], 2
// Output: 1
// Example 3:

// Input: [1,3,5,6], 7
// Output: 4
// Example 4:

// Input: [1,3,5,6], 0
// Output: 0

// Tags: binary_search, array

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& a, int target) {
    int n = a.size();
    if (n == 0) {
      return 0;
    }
    return lb(a, n, target);
  }
  int lb(vector<int>& a, int n, int target) {
    int l = 0, h = n - 1;
    while (l < h) {
      int mid = l + (h - l) / 2;
      if (a[mid] >= target) {
        h = mid;
      } else {
        l = mid + 1;
      }
    }
    if (a[l] < target) {
      return l + 1;
    }
    return l;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{1, 3, 5, 6}, 5},
                                       {{1, 3, 5, 6}, 2},
                                       {{1, 3, 5, 6}, 7},
                                       {{1, 3, 5, 6}, 0}};
  Solution solution;
  for (auto& i : tc) {
    cout << solution.searchInsert(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
