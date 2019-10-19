// Determine whether an integer is a palindrome. An integer is a palindrome when
// it reads the same backward as forward.

// Example 1:

// Input: 121
// Output: true
// Example 2:

// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it
// becomes 121-. Therefore it is not a palindrome. Example 3:

// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Follow up:

// Coud you solve it without converting the integer to a string?

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

class Solution1 {
  // Using string
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    string s = to_string(x);
    int l = s.length();
    for (int i = 0; i < l / 2; i++) {
      if (s[i] != s[l - i - 1]) {
        return false;
      }
    }
    return true;
  }
};
class Solution {
  // Without using string
 public:
  bool isPalindrome(int n) {
    if (n < 0) {
      return false;
    }
    int orig = n;
    int d = 0;
    while (n) {
      if (d > INT_MAX / 10 || (d == INT_MAX / 10 && n % 10 > 7)) {
        // Integer Overflow
        return false;
      }
      d = d * 10 + n % 10;
      n /= 10;
    }
    return d == orig;
  }
};
void solve() {
  int tc[] = {1, -1, 0, 22, 2442, 3213, 100, 121, 123, -121, -123, 2147483647};
  int nc = sizeof(tc) / sizeof(tc[0]);
  Solution s;
  for (int i = 0; i < nc; i++) {
    cout << tc[i] << " " << boolalpha << s.isPalindrome(tc[i]) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
