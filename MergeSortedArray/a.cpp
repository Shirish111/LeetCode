// Merge Sorted Array

// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
// one sorted array.

// Note:

// The number of elements initialized in nums1 and nums2 are m and n
// respectively. You may assume that nums1 has enough space (size that is
// greater or equal to m + n) to hold additional elements from nums2. Example:

// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]

// Tags: merge

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& a, int m, vector<int>& b, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (a[i] > b[j]) {
        a[k--] = a[i--];
      } else {
        a[k--] = b[j--];
      }
    }
    while (j >= 0) {
      a[k--] = b[j--];
    }
  }
};
void solve() {
  vector<pair<vector<int>, vector<int>>> tc = {{{1, 2, 3, 0, 0, 0}, {2, 5, 6}}};
  Solution s;
  for (auto& i : tc) {
    s.merge(i.first, i.first.size() - i.second.size(), i.second,
            i.second.size());
    copy(i.first.begin(), i.first.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
