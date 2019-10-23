// 3Sum Closest

// Given an array nums of n integers and an integer target, find three integers
// in nums such that the sum is closest to target. Return the sum of the three
// integers. You may assume that each input would have exactly one solution.

// Example:

// Given array nums = [-1, 2, 1, -4], and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

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
  int threeSumClosest(vector<int>& a, int target) {
    int mn = INT_MAX, value, df;
    int n = a.size(), fp, bp, sm, ps;
    sort(a.begin(), a.end());
    int i = 0;
    while (i < n - 2) {
      fp = i + 1;
      bp = n - 1;
      while (fp < bp) {
        sm = a[i] + a[fp] + a[bp];
        if (sm == target) {
          return sm;
        }
        if (sm < target) {
          fp++;
        } else {
          bp--;
        }
        df = abs(sm - target);
        if (mn > df) {
          mn = df;
          value = sm;
        }
      }
      i++;
    }
    return value;
  }
};
void solve() {
  Solution solution;
  vector<int> a = {1, 2, 4, 8, 16, 32, 64, 128};
  int ans = solution.threeSumClosest(a, 82);
  cout << ans << "\n";
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
