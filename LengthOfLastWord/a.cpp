// Length of Last Word

// Given a string s consists of upper/lower-case alphabets and empty space
// characters ' ', return the length of last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space
// characters only.

// Example:

// Input: "Hello World"
// Output: 5

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
  int lengthOfLastWord(string s) {
    int n = s.length() - 1;
    int cnt = 0;
    while (n >= 0 && s[n] == ' ') {
      n--;
    }
    while (n >= 0 && s[n] != ' ') {
      cnt++;
      n--;
    }
    return cnt;
  }
};
void solve() {
  vector<string> tc = {"Hello World", "Hello", "Hello "};
  Solution s;
  for (auto &i : tc) {
    cout << i << " " << s.lengthOfLastWord(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
