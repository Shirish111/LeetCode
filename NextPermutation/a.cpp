// Next Permutation

// Implement next permutation, which rearranges numbers into the
// lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest
// possible order (ie, sorted in ascending order).

// The replacement must be in-place and use only constant extra memory.

// Here are some examples. Inputs are in the left-hand column and its
// corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

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
  void nextPermutation(vector<int>& a) {
    int n = a.size();
    int i = n - 2;
    while (i >= 0 && a[i + 1] <= a[i]) {
      i--;
    }
    if (i >= 0) {
      int j = n - 1;
      while (j >= 0 && a[j] <= a[i]) {
        j--;
      }
      swap(a[i], a[j]);
    }
    reverse(a.begin() + i + 1, a.end());
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 3}, {3, 2, 1}, {1, 1, 5}};
  Solution solution;
  for (auto& i : tc) {
    solution.nextPermutation(i);
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
