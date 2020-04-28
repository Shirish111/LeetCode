// Longest Consecutive Sequence

// Given an unsorted array of integers, find the length of the longest
// consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.

// Tags: dynamic_programming, set

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> nums_set;
    for (auto &i : nums) {
      nums_set.insert(i);
    }
    int longest_streak = 0;
    for (auto &i : nums_set) {
      if (nums_set.find(i - 1) == nums_set.end()) {
        int cur = i;
        int streak = 1;
        while (nums_set.find(cur + 1) != nums_set.end()) {
          streak++;
          cur++;
        }
        longest_streak = max(longest_streak, streak);
      }
    }
    return longest_streak;
  }
};
void solve() {
  vector<vector<int>> tc = {{100, 4, 200, 1, 3, 2}, {}};
  Solution s;
  for (auto &i : tc) {
    cout << s.longestConsecutive(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
