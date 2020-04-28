// Merge Intervals

// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// NOTE: input types have been changed on April 15, 2019. Please reset to
// default code definition to get new method signature.

// Tags: intervals, sorting

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &a) {
    int n = a.size();
    vector<vector<int>> ans;
    if (n == 0) {
      return ans;
    }
    sort(a.begin(), a.end(), [](auto &a, auto &b) -> bool {
      if (a[0] == b[0]) {
        return a[0] < b[0];
      }
      return a[0] < b[0];
    });
    int ai = 0;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++) {
      if (ans[ai][1] >= a[i][0]) {
        ans[ai][1] = max(ans[ai][1], a[i][1]);
      } else {
        ans.push_back(a[i]);
        ai++;
      }
    }
    return ans;
  }
};
void solve() {
  vector<vector<vector<int>>> tc = {{{1, 3}, {2, 6}, {8, 10}, {15, 18}},
                                    {{1, 4}, {4, 5}},
                                    {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> ans = s.merge(i);
    for (auto &j : ans) {
      copy(j.begin(), j.end(), ostream_iterator<int>(cout, " "));
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
