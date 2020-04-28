// Search in Rotated Sorted Array

// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its
// index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Tags: array, rotate, binary_search

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int search(vector<int>& a, int target) {
    int n = a.size();
    int min_index = find_min_index(a, n);
    return rotated_bs(a, n, target, min_index);
  }
  int rotated_bs(vector<int>& a, int n, int target, int pivot) {
    int l = 0, h = n - 1;
    while (l <= h) {
      int mid = l + (h - l) / 2;
      int realmid = (mid + pivot) % n;
      if (a[realmid] == target) {
        return realmid;
      } else if (a[realmid] < target) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
    return -1;
  }
  int find_min_index(vector<int>& a, int n) {
    int l = 0, h = n - 1;
    while (l < h) {
      int mid = (l + h) / 2;
      if (a[mid] < a[h]) {
        h = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{4, 5, 6, 7, 0, 1, 2}, 0},
                                       {{4, 5, 6, 7, 0, 1, 2}, 3}};
  Solution solution;
  for (auto& i : tc) {
    cout << solution.search(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
