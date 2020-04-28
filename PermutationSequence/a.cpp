// Permutation Sequence

// The set [1,2,3,...,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the
// following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note:

// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.
// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"

// Tags: permutations, factorial

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    vector<int> num(n);
    iota(num.begin(), num.end(), '1');
    vector<int> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i;
    }
    k--;
    string ans;
    for (int i = 1; i <= n; i++) {
      int index = k / fact[n - i];
      ans.append(1, num[index]);
      k -= index * fact[n - i];
      num.erase(num.begin() + index);
    }
    return ans;
  }
};
void solve() {
  vector<pair<int, int>> tc = {{3, 3}, {4, 9}};
  Solution s;
  for (auto &i : tc) {
    cout << s.getPermutation(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
