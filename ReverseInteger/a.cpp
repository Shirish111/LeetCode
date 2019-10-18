// Reverse Integer

// Given a 32-bit signed integer, reverse digits of an integer.

// Example 1:

// Input: 123
// Output: 321
// Example 2:

// Input: -123
// Output: -321
// Example 3:

// Input: 120
// Output: 21
// Note:
// Assume we are dealing with an environment which could only store integers
// within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
// this problem, assume that your function returns 0 when the reversed integer
// overflows.

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

int n;
int reverse_integer() {
  int rev = 0;
  while (n) {
    int d = n % 10;
    n = n / 10;
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && d > 7)) {
      return 0;
    }
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && d < -8)) {
      return 0;
    }
    rev = rev * 10 + d;
  }
  return rev;
}
void solve() {
  cin >> n;
  cout << INT_MAX << " " << INT_MIN << "\n";
  cout << reverse_integer() << "\n";
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}