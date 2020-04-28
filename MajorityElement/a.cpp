// Majority Element

// Given an array of size n, find the majority element. The majority element is
// the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always
// exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2

// Tags: moore_voting_algorithm, majority_element

#include <bits/stdc++.h>
using namespace std;

class SolutionH {
 public:
  int majorityElement(vector<int> &a) {
    unordered_map<int, int> m;
    for (auto &i : a) {
      m[i]++;
    }
    int mc = floor(a.size() / 2.0) + 1;
    for (auto &i : m) {
      if (i.second >= mc) {
        return i.first;
      }
    }
    return -1;
  }
};
class Solution {
 public:
  int majorityElement(vector<int> &a) {
    int count = 0;
    int candidate = -1;
    for (auto &i : a) {
      if (count == 0) {
        candidate = i;
      }
      count += candidate == i ? 1 : -1;
    }
    return candidate;
  }
};
void solve() {
  vector<vector<int>> tc = {{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}};
  Solution s;
  for (auto &i : tc) {
    cout << s.majorityElement(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
