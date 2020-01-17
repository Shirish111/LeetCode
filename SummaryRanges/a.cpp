// Summary Ranges

// Given a sorted integer array without duplicates, return the summary of its
// ranges.

// Example 1:

// Input:  [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
// Example 2:

// Input:  [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int> &a) {
    vector<string> ans;
    size_t n = a.size();
    if (n == 0) {
      return ans;
    }
    if (n == 1) {
      ans.push_back(to_string(a[0]));
      return ans;
    }
    int beg = a[0];
    for (size_t i = 1; i < n; ++i) {
      if (a[i] != a[i - 1] + 1) {
        if (beg == a[i - 1]) {
          ans.push_back(to_string(beg));
          beg = a[i];
        } else {
          ans.push_back(to_string(beg) + "->" + to_string(a[i - 1]));
          beg = a[i];
        }
      }
    }
    if (a[n - 1] == a[n - 2] + 1) {
      ans.push_back(to_string(beg) + "->" + to_string(a[n - 1]));
    } else {
      ans.push_back(to_string(beg));
    }
    return ans;
  }
};
void solve() {
  vector<vector<int>> tc = {{0, 1, 2, 4, 5, 7}, {0, 2, 3, 4, 6, 8, 9}, {-1}};
  Solution s;
  for (auto &i : tc) {
    vector<string> ans = s.summaryRanges(i);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
