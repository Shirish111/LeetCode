// Contains Duplicate II

// Given an array of integers and an integer k, find out whether there are two
// distinct indices i and j in the array such that nums[i] = nums[j] and the
// absolute difference between i and j is at most k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

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
  bool containsNearbyDuplicate(vector<int>& a, int k) {
    unordered_map<int, int> m;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
      auto t1 = m.find(a[i]);
      if (m.find(a[i]) != m.end()) {
        if (i - t1->second <= k) {
          return true;
        }
        t1->second = i;
        continue;
      }
      m[a[i]] = i;
    }
    return false;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {
      {{1, 2, 3, 1}, 3}, {{1, 0, 1, 1}, 1}, {{1, 2, 3, 1, 2, 3}, 2}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.containsNearbyDuplicate(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
