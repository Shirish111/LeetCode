// Longest Palindromic Substring

// Given a string s, find the longest palindromic substring in s. You may assume
// that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"

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

string s;
ll n;
ll m[101][101];
ll longest_palindromic_substring() {
  ll mx = 1;
  F(i, 0, n) { m[i][i] = 1; }
  F(i, 0, n - 1) { m[i + 1][i] = -1; }
  ll i;
  F(k, 1, n) {
    i = 0;
    F(j, k, n) {
      if (s[i] == s[j]) {
        m[i][j] = 2 + m[i + 1][j - 1];
        mx = max(mx, m[i][j]);
      } else {
        m[i][j] = 0;
      }
      i++;
    }
  }
  return mx;
}
void solve() {
  cin >> s;
  n = s.length();
  cout << longest_palindromic_substring() << "\n";
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
