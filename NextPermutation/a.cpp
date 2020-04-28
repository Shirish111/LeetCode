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

// Tags: permutations, recursion, string_manipulation

#include <bits/stdc++.h>
using namespace std;

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
