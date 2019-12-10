// Fraction to Recurring Decimal

// Given two integers representing the numerator and denominator of a fraction,
// return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in
// parentheses.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 2, denominator = 3
// Output: "0.(6)"

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
  string fractionToDecimal(int n, int d) {
    if (n == 0) {
      return "0";
    }
    string s;
    if ((n > 0) ^ (d > 0)) {
      s.append(1, '-');
    }
    long long num = abs(n);
    long long den = abs(d);
    // Integral Part
    s.append(to_string(num / den));
    num = num % den;
    if (num == 0) {
      return s;
    }
    // Fractional Part
    s.append(1, '.');
    unordered_map<long long, int> m;
    m[num] = s.length();
    while (num != 0) {
      num *= 10;
      s.append(to_string(num / den));
      num = num % den;
      if (m.find(num) != m.end()) {
        int index = m[num];
        s.insert(index, "(");
        s.append(1, ')');
        break;
      } else {
        m[num] = s.length();
      }
    }
    return s;
  }
};
void solve() {
  vector<pair<int, int>> tc = {{1, 2}, {2, 1}, {2, 3}, {22, 7}};
  Solution s;
  for (auto &i : tc) {
    cout << s.fractionToDecimal(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
