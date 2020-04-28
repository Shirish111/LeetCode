// 4Sum

// Given an array nums of n integers and an integer target, are there elements
// a, b, c, and d in nums such that a + b + c + d = target? Find all unique
// quadruplets in the array which gives the sum of target.

// Note:

// The solution set must not contain duplicate quadruplets.

// Example:

// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

// Tags: sorting, two_pointers
// Difficulty: Medium
// Important: Skipping the elements for unique triplets
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& a, int target) {
    vector<vector<int>> ans;
    int n = a.size(), sm, fp, bp;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 3;) {
      for (int j = i + 1; j < n - 2;) {
        fp = j + 1;
        bp = n - 1;
        while (fp < bp) {
          sm = a[i] + a[j] + a[fp] + a[bp];
          if (sm == target) {
            ans.push_back({a[i], a[j], a[fp], a[bp]});
            fp++;
            bp--;
            while (fp < bp && a[fp] == a[fp - 1]) fp++;
            while (fp < bp && a[bp] == a[bp + 1]) bp--;
          } else if (sm < target) {
            fp++;
          } else {
            bp--;
          }
        }
        j++;
        while (j < n - 1 && a[j] == a[j - 1]) j++;
      }
      i++;
      while (i < n && a[i] == a[i - 1]) i++;
    }
    return ans;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{1, 0, -1, 0, -2, 2}, 0}};
  Solution s;
  for (auto& i : tc) {
    vector<vector<int>> ans = s.fourSum(i.first, i.second);
    for (auto& j : ans) {
      for (auto& k : j) {
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
