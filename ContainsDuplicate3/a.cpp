// Contains Duplicate III

// Given an array of integers, find out whether there are two distinct indices i
// and j in the array such that the absolute difference between nums[i] and
// nums[j] is at most t and the absolute difference between i and j is at most
// k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
// Example 3:

// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
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
  bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
    int n = a.size();
    if (n <= 1 || k < 1 || t < 0) {
      return false;
    }
    unordered_map<long long, long long> m;
    for (int i = 0; i < n; ++i) {
      long long remapped_value = (long long)a[i] - INT_MIN;
      long long bucket = remapped_value / (t + 1LL);
      if (m.find(bucket) != m.end() ||
          (m.find(bucket - 1) != m.end() &&
           remapped_value - m[bucket - 1] <= t) ||
          (m.find(bucket + 1) != m.end() &&
           m[bucket + 1] - remapped_value <= t)) {
        return true;
      }
      if (i >= k) {
        long long remapped_value2 = (long long)a[i - k] - INT_MIN;
        m.erase(m.find(remapped_value2 / (t + 1LL)));
      }
      m[bucket] = remapped_value;
    }
    return false;
  }
};
void solve() {
  struct Q {
    vector<int> a;
    int k, t;
  };
  vector<Q> tc = {Q{{1, 2, 3, 1}, 3, 0}, Q{{1, 0, 1, 1}, 1, 2},
                  Q{{1, 5, 9, 1, 5, 9}, 2, 3}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.containsNearbyAlmostDuplicate(i.a, i.k, i.t) << "\n";
  }
}
int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
