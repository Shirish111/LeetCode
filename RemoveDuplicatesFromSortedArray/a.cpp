// Remove Duplicates from Sorted Array

// Given a sorted array nums, remove the duplicates in-place such that each
// element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying
// the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums
// being 1 and 2 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,2,2,3,3,4],

// Your function should return length = 5, with the first five elements of nums
// being modified to 0, 1, 2, 3, and 4 respectively.

// It doesn't matter what values are set beyond the returned length.
// Clarification:

// Confused why the returned value is an integer but your answer is an array?

// Note that the input array is passed in by reference, which means modification
// to the input array will be known to the caller as well.

// Internally you can think of this:

// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);

// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len
// elements. for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

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
  int removeDuplicates(vector<int>& v) {
    int idx = 0, cur = 1, n = v.size();
    while (cur < n) {
      if (v[idx] != v[cur]) {
        idx++;
        v[idx] = v[cur];
      }
      cur++;
    }
    return min(n, idx + 1);
  }
};

void solve() {
  vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution solution;
  int n = solution.removeDuplicates(v);
  for (int i = 0; i < n; i++) {
    cout << v[i] << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
