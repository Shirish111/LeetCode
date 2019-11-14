// Remove Duplicates from Sorted Array II

// Given a sorted array nums, remove the duplicates in-place such that
// duplicates appeared at most twice and return the new length.

// Do not allocate extra space for another array, you must do this by modifying
// the input array in-place with O(1) extra memory.

// Example 1:

// Given nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums
// being 1, 1, 2, 2 and 3 respectively.

// It doesn't matter what you leave beyond the returned length.
// Example 2:

// Given nums = [0,0,1,1,1,1,2,3,3],

// Your function should return length = 7, with the first seven elements of nums
// being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

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
  int removeDuplicates(vector<int>& a) {
    int n = a.size();
    if (n == 0) {
      return 0;
    }
    int i = 0, j = 1, cnt = 1, cur = a[0];
    while (j < n) {
      if (a[i] == a[j]) {
        if (cnt < 2) {
          i += 1;
          swap(a[i], a[j]);
          cnt++;
        }
      } else {
        i += 1;
        cnt = 1;
        swap(a[i], a[j]);
        cur = a[i];
      }
      j++;
    }
    return i + 1;
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 1, 1, 2, 2, 3}, {0, 0, 1, 1, 1, 1, 2, 3, 3}};
  Solution s;
  for (auto& i : tc) {
    int n = s.removeDuplicates(i);
    for (int j = 0; j < n; j++) {
      cout << i[j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
