// Contains Duplicate

// Given an array of integers, find if the array contains any duplicates.

// Your function should return true if any value appears at least twice in the
// array, and it should return false if every element is distinct.

// Example 1:

// Input: [1,2,3,1]
// Output: true
// Example 2:

// Input: [1,2,3,4]
// Output: false
// Example 3:

// Input: [1,1,1,3,3,4,3,2,4,2]
// Output: true

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
  bool containsDuplicate(vector<int>& a) {
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 1; i < n; ++i) {
      if (a[i - 1] == a[i]) {
        return true;
      }
    }
    return false;
  }
};
class SolutionSet {
 public:
  bool containsDuplicate(vector<int>& a) {
    unordered_set<int> st;
    for (auto& i : a) {
      if (st.find(i) != st.end()) {
        return true;
      }
      st.insert(i);
    }
    return false;
  }
};
void solve() {
  vector<vector<int>> tc = {
      {1, 2, 3, 1}, {1, 2, 3, 4}, {1, 1, 1, 3, 3, 4, 3, 2, 4, 2}};
  Solution s;
  for (auto& i : tc) {
    cout << boolalpha << s.containsDuplicate(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
