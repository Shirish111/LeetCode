// Given a string, find the length of the longest substring without repeating
// characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
//              Note that the answer must be a substring, "pwke" is a
//              subsequence and not a substring.

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
ll longest_substring_without_repeating_chars_length() {
  ll start = -1;
  ll mx = 0;
  vector<ll> v(256, -1);
  F(end, 0, n) {
    if (v[s[end]] != -1) {
      start = start < v[s[end]] ? v[s[end]] : start;
    }
    mx = max(mx, end - start);
    v[s[end]] = end;
  }
  return mx;
}
void solve() {
  cin >> s;
  n = s.length();
  cout << longest_substring_without_repeating_chars_length();
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}