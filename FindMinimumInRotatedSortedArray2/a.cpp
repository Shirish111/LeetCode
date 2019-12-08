// Find Minimum in Rotated Sorted Array II

// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// The array may contain duplicates.

// Example 1:

// Input: [1,3,5]
// Output: 1
// Example 2:

// Input: [2,2,2,0,1]
// Output: 0
// Note:

// This is a follow up problem to Find Minimum in Rotated Sorted Array.
// Would allow duplicates affect the run-time complexity? How and why?

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
  int findMin(vector<int>& a) {
    int l = 0, h = a.size() - 1;
    while (l < h) {
      int mid = l + (h - l) / 2;
      if (a[mid] > a[h]) {
        l = mid + 1;
      } else if (a[mid] < a[h]) {
        h = mid;
      } else {
        h--;
      }
    }
    return a[l];
  }
};
void solve() {
  vector<vector<int>> tc = {{0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 0, 0, 0, 0, 0},
                            {1, 0, 0, 0, 2},
                            {1, 1, 1, 1, 1, 1, 0, 0, 1},
                            {1, 1, 1, 0},
                            {
                                1,
                                0,
                                0,
                                1,
                                1,
                                1,
                                1,
                                1,
                            }};
  Solution s;
  for (auto& i : tc) {
    cout << s.findMin(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
