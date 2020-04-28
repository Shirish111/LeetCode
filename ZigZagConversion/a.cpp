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

// Tags: miscellaneous

#include <bits/stdc++.h>
using namespace std;

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
