// 3Sum

// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// Tags: sorting, two_pointers
// Difficulty: Medium
// Important: Skipping the elements for unique triplets
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &a) {
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    int sm, n = a.size(), fp, bp;
    for (int i = 0; i < n - 2;) {
      fp = i + 1;
      bp = n - 1;
      while (fp < bp) {
        sm = a[i] + a[fp] + a[bp];
        if (sm == 0) {
          ans.push_back({a[i], a[fp], a[bp]});
          fp++;
          bp--;
          while (fp < bp && a[fp] == a[fp - 1]) fp++;
          while (fp < bp && a[bp] == a[bp + 1]) bp--;
        } else if (sm < 0) {
          fp++;
        } else {
          bp--;
        }
      }
      i++;
      while (i < n && a[i] == a[i - 1]) i++;
    }
    return ans;
  }
};

void solve() {
  vector<vector<int>> tc = {{-1, 0, 1, 2, -1, -4}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> ans = s.threeSum(i);
    for (auto &j : ans) {
      for (auto &k : j) {
        cout << k << " ";
      }
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
