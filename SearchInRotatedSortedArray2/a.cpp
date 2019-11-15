// Search in Rotated Sorted Array II

// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.

// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

// You are given a target value to search. If found in the array return true,
// otherwise return false.

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
// Follow up:

// This is a follow up problem to Search in Rotated Sorted Array, where nums may
// contain duplicates. Would this affect the run-time complexity? How and why?

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
  bool search(vector<int>& a, int t) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      if (a[i] == t) {
        return true;
      }
    }
    return false;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{2, 5, 6, 0, 0, 1, 2}, 0},
                                       {{2, 5, 6, 0, 0, 1, 2}, 3},
                                       {{1, 1}, 0},
                                       {{3, 1}, 1}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.search(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
