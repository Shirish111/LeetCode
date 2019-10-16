// ZigZag Conversion

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this: (you may want to display this pattern in a fixed font for
// better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a
// number of rows:

// string convert(string s, int numRows);
// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

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

ll n, l;
string s, ans;
void zigzag_pattern() {
  ll d1 = ((n - 1) << 1LL), d2 = 0;
  l = s.length();
  ll j;
  bool tmp;
  F(i, 0, n) {
    j = i;
    tmp = true;
    while (j < l) {
      ans.append(1, s[j]);
      if (d1 && d2) {
        if (tmp) {
          j += d1;
        } else {
          j += d2;
        }
      } else {
        j += d1 + d2;  // If one of them is zero then add the other one
      }
      tmp = !tmp;
    }
    d1 -= 2;
    d2 += 2;
  }
  cout << ans << "\n";
}
void solve() {
  cin >> s;
  cin >> n;
  zigzag_pattern();
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
