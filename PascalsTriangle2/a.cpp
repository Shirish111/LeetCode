// Pascal's Triangle II

// Given a non-negative index k where k ≤ 33, return the kth index row of the
// Pascal's triangle.

// Note that the row index starts from 0.

// In Pascal's triangle, each number is the sum of the two numbers directly
// above it.

// Example:

// Input: 3
// Output: [1,3,3,1]
// Follow up:

// Could you optimize your algorithm to use only O(k) extra space?

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
  vector<int> getRow(int index) {
    vector<int> a;
    a.assign(index + 1, 0);
    a[0] = 1;
    int i = 1, p;
    while (i <= index) {
      p = a[0];
      for (int j = 1; j < i; j++) {
        a[j] += p;
        p = a[j] - p;
      }
      a[i] = 1;
      i++;
    }
    return a;
  }
};
void solve() {
  vector<int> tc = {0, 1, 2, 3, 4, 5};
  Solution s;
  for (auto &i : tc) {
    vector<int> ans = s.getRow(i);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
