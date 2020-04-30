// Find the Duplicate Number

// Given an array nums containing n + 1 integers where each integer is between 1
// and n (inclusive), prove that at least one duplicate number must exist.
// Assume that there is only one duplicate number, find the duplicate one.

// Example 1:

// Input: [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: [3,1,3,4,2]
// Output: 3
// Note:

// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated
// more than once.

// Tags: list, array, cycle, interview, floyd
// Difficulty: Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int> &a) {
    int tortoise = a[0];
    int hare = a[0];
    do {
      hare = a[a[hare]];
      tortoise = a[tortoise];
    } while (tortoise != hare);
    tortoise = a[0];
    while (tortoise != hare) {
      tortoise = a[tortoise];
      hare = a[hare];
    }
    return tortoise;
  }
};

void solve() {
  vector<vector<int>> tc = {{1, 3, 4, 2, 2}, {3, 1, 3, 4, 2}};
  Solution s;
  for (auto &i : tc) {
    cout << s.findDuplicate(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
