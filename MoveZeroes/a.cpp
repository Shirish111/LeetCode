// Move Zeroes

// Given an array nums, write a function to move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.

// Difficulty: Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& a) {
    int n = a.size();
    int lastNonZeroIndex = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != 0) {
        swap(a[lastNonZeroIndex++], a[i]);
      }
    }
  }
};

class Solution2 {
 public:
  void moveZeroes(vector<int>& a) {
    int n = a.size();
    int lastNonZeroIndex = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != 0) {
        a[lastNonZeroIndex++] = a[i];
      }
    }
    for (int i = lastNonZeroIndex; i < n; ++i) {
      a[i] = 0;
    }
  }
};

void solve() {
  vector<vector<int>> tc = {{0, 1, 0, 3, 12}};
  Solution2 s;
  for (auto& i : tc) {
    s.moveZeroes(i);
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
