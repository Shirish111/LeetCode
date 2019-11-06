// First Missing Positive

// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1
// Note:

// Your algorithm should run in O(n) time and uses constant extra space.

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
  int firstMissingPositive(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 1;
    for (auto& i : a) {
      if (i <= 0 || i > n) {
        i = (n + 1);
      }
    }
    for (int i = 0; i < n; i++) {
      int abs_elem = abs(a[i]);
      if (abs_elem != (n + 1) && a[abs_elem - 1] > 0) {
        a[abs_elem - 1] *= -1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 0}, {3, 4, -1, 1}, {7, 8, 9, 11, 12},
                            {},        {1},           {1, 2, 3}};
  Solution s;
  for (auto& i : tc) {
    cout << s.firstMissingPositive(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
