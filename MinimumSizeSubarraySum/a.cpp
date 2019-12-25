// Minimum Size Subarray Sum

// Given an array of n positive integers and a positive integer s, find the
// minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
// one, return 0 instead.

// Example:

// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem
// constraint. Follow up: If you have figured out the O(n) solution, try coding
// another solution of which the time complexity is O(n log n).

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
  int minSubArrayLen(int s, vector<int>& a) {
    int sm = 0, mn = INT_MAX;
    int n = a.size();
    int i, j;
    i = j = 0;
    while (j < n) {
      sm += a[j];
      while (i <= j && sm - a[i] >= s) {
        sm -= a[i];
        i++;
      }
      if (sm >= s && mn > j - i + 1) {
        mn = j - i + 1;
      }
      j++;
    }
    return mn == INT_MAX ? 0 : mn;
  }
};
void solve() {
  vector<pair<int, vector<int>>> tc = {{7, {2, 3, 1, 2, 4, 3}}, {100, {}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.minSubArrayLen(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
