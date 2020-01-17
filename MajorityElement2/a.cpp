// Majority Element II

// Given an integer array of size n, find all elements that appear more than ⌊
// n/3 ⌋ times.

// Note: The algorithm should run in linear time and in O(1) space.

// Example 1:

// Input: [3,2,3]
// Output: [3]
// Example 2:

// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> majorityElement(vector<int> &a) {
    unordered_map<int, int> m;
    for (auto &i : a) {
      m[i]++;
    }
    vector<int> ans;
    int ts = a.size() / 3;
    for (auto &i : m) {
      if (i.second > ts) {
        ans.push_back(i.first);
      }
    }
    return ans;
  }
};
void solve() {
  vector<vector<int>> tc = {{3, 2, 3}, {1, 1, 1, 3, 3, 2, 2, 2}};
  Solution s;
  for (auto &i : tc) {
    vector<int> a = s.majorityElement(i);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
