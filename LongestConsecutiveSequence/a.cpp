// Longest Consecutive Sequence

// Given an unsorted array of integers, find the length of the longest
// consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define PB push_back
#define F0(I, N) for (ll I = 0; I < N; I++)
#define F1(I, N) for (ll I = 1; I <= N; I++)
#define F(I, X, N) for (ll I = X; I < N; I++)
#define R0(I, N) for (ll I = N - 1; I >= 0; I--)
#define R1(I, N) for (ll I = N; I > 0; I--)
#define R(I, X, N) for (ll I = N - 1; I >= X; I--)
#define A(X) X.begin(), X.end()

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
