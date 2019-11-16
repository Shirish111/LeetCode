// Gray Code

// The gray code is a binary numeral system where two successive values differ
// in only one bit.

// Given a non-negative integer n representing the total number of bits in the
// code, print the sequence of gray code. A gray code sequence must begin with
// 0.

// Example 1:

// Input: 2
// Output: [0,1,3,2]
// Explanation:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2

// For a given n, a gray code sequence may not be uniquely defined.
// For example, [0,2,3,1] is also a valid gray code sequence.

// 00 - 0
// 10 - 2
// 11 - 3
// 01 - 1
// Example 2:

// Input: 0
// Output: [0]
// Explanation: We define the gray code sequence to begin with 0.
//              A gray code sequence of n has size = 2n, which for n = 0 the
//              size is 20 = 1. Therefore, for n = 0 the gray code sequence is
//              [0].

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
  vector<int> grayCode(int n) {
    vector<int> a;
    for (long long i = 0; i < (1 << n); i++) {
      a.push_back(i ^ (i >> 1LL));
    }
    return a;
  }
};
void solve() {
  vector<int> tc = {2, 0, 4};
  Solution s;
  for (auto &i : tc) {
    vector<int> res = s.grayCode(i);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
