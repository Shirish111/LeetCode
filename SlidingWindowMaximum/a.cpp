// Sliding Window Maximum

// Given an array nums, there is a sliding window of size k which is moving from
// the very left of the array to the very right. You can only see the k numbers
// in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

// Example:

// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7]
// Explanation:

// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Note:
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
// array.

// Follow up:
// Could you solve it in linear time?

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& a, int k) {
    vector<int> ans;
    int n = a.size();
    if (n == 0) {
      return ans;
    }
    deque<int> q;
    for (int i = 0; i < n; ++i) {
      while (!q.empty() && q.front() < i - k + 1) {
        q.pop_front();
      }
      while (!q.empty() && a[q.back()] < a[i]) {
        q.pop_back();
      }
      q.push_back(i);
      if (i >= k - 1) {
        ans.push_back(a[q.front()]);
      }
    }
    return ans;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{1, 3, -1, -3, 5, 3, 6, 7}, 3},
                                       {{7, 2, 4}, 2}};
  Solution s;
  for (auto& i : tc) {
    vector<int> ans = s.maxSlidingWindow(i.first, i.second);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
