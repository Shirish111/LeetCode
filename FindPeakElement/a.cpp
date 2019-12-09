// Find Peak Element

// A peak element is an element that is greater than its neighbors.

// Given an input array nums, where nums[i] != nums[i+1], find a peak element
// and return its index.

// The array may contain multiple peaks, in that case return the index to any
// one of the peaks is fine.

// You may imagine that nums[-1] = nums[n] = -INF.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index
// number 2. Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1 where the peak
// element is 2,
//              or index number 5 where the peak element is 6.
// Note:

// Your solution should be in logarithmic complexity.

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

// Linear Solution
class SolutionL {
 public:
  int findPeakElement(vector<int> &a) {
    for (int i = 0; i < a.size() - 1; i++) {
      if (a[i] > a[i + 1]) {
        return i;
      }
    }
    return a.size() - 1;
  }
};

// Binary Search
class Solution {
 public:
  int findPeakElement(vector<int> &a) {
    int l = 0, h = a.size() - 1;
    while (l < h) {
      int mid = l + (h - l) / 2;
      if (a[mid] > a[mid + 1]) {
        h = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 3, 1}, {1, 2, 1, 3, 5, 6, 4}};
  Solution s;
  for (auto &i : tc) {
    cout << s.findPeakElement(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
