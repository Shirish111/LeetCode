// Find First and Last Position of Element in Sorted Array

// Given an array of integers nums sorted in ascending order, find the starting
// and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Tags: binary_search

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& a, int target) {
    vector<int> ans;
    int n = a.size();
    ans.push_back(lb(a, n, target));
    ans.push_back(ans[0] == -1 ? -1 : ub(a, n, target));
    return ans;
  }
  int lb(vector<int>& a, int n, int target) {
    if (n == 0) {
      return -1;
    }
    int l = 0, h = n - 1;
    while (l < h) {
      int mid = l + (h - l) / 2;
      if (a[mid] >= target) {
        h = mid;
      } else {
        l = mid + 1;
      }
    }
    if (a[l] == target) {
      return l;
    }
    return -1;
  }
  int ub(vector<int>& a, int n, int target) {
    if (n == 0) {
      return -1;
    }
    int l = 0, h = n - 1;
    while (l < h) {
      int mid = l + (h - l + 1) / 2;
      if (a[mid] <= target) {
        l = mid;
      } else {
        h = mid - 1;
      }
    }
    if (a[h] == target) {
      return h;
    }
    return -1;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{5, 7, 7, 8, 8, 10}, 8},
                                       {{5, 7, 7, 8, 8, 10}, 6}};
  Solution solution;
  for (auto& i : tc) {
    vector<int> ans = solution.searchRange(i.first, i.second);
    copy(i.first.begin(), i.first.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
