// Find Minimum in Rotated Sorted Array

// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Example 1:

// Input: [3,4,5,1,2]
// Output: 1
// Example 2:

// Input: [4,5,6,7,0,1,2]
// Output: 0

// Tags: binary_search

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& a) {
    int l = 0, h = a.size() - 1;
    while (l < h) {
      int mid = (l + h) / 2;
      if (a[mid] < a[h]) {
        h = mid;
      } else {
        l = mid + 1;
      }
    }
    return a[l];
  }
};
void solve() {
  vector<vector<int>> tc = {{3, 4, 5, 1, 2}, {4, 5, 6, 7, 0, 1, 2}};
  Solution s;
  for (auto& i : tc) {
    cout << s.findMin(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
