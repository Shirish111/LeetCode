// Merge Sorted Array

// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
// one sorted array.

// Note:

// The number of elements initialized in nums1 and nums2 are m and n
// respectively. You may assume that nums1 has enough space (size that is
// greater or equal to m + n) to hold additional elements from nums2. Example:

// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]

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
  void merge(vector<int>& a, int m, vector<int>& b, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (a[i] > b[j]) {
        a[k--] = a[i--];
      } else {
        a[k--] = b[j--];
      }
    }
    while (j >= 0) {
      a[k--] = b[j--];
    }
  }
};
void solve() {
  vector<pair<vector<int>, vector<int>>> tc = {{{1, 2, 3, 0, 0, 0}, {2, 5, 6}}};
  Solution s;
  for (auto& i : tc) {
    s.merge(i.first, i.first.size() - i.second.size(), i.second,
            i.second.size());
    copy(i.first.begin(), i.first.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
