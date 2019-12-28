// Kth Largest Element in an Array

// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.

// Example 1:

// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
// Example 2:

// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

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
  int findKthLargest(vector<int>& a, int k) {
    int n = a.size();
    k = n - k;
    int l = 0, h = n - 1;
    while (l < h) {
      int p = partition(a, l, h);
      if (p < k) {
        l = p + 1;
      } else if (p > k) {
        h = p - 1;
      } else {
        break;
      }
    }
    return a[k];
  }
  int partition(vector<int>& a, int l, int h) {
    swap(a[(l + h) / 2], a[h]);
    int i = l, j = l;
    while (j < h) {
      if (a[j] < a[h]) {
        swap(a[i], a[j]);
        i++;
      }
      j++;
    }
    swap(a[i], a[h]);
    return i;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{3, 2, 1, 5, 6, 4}, 2},
                                       {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4}};
  Solution s;
  for (auto& i : tc) {
    cout << s.findKthLargest(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
