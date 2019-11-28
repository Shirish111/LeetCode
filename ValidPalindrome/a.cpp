// Valid Palindrome

// Given a string, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid
// palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

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
  bool isPalindrome(string s) {
    int h = s.length() - 1;
    int l = 0;
    while (l < h) {
      if (isalnum(s[l]) && isalnum(s[h])) {
        if (s[l] < 58 || s[h] < 58) {
          if (s[l] != s[h]) {
            return false;
          }
        } else if ((s[l] & 31) != (s[h] & 31)) {
          return false;
        }
        l++;
        h--;
      } else if (!isalnum(s[l])) {
        l++;
      } else if (!isalnum(s[h])) {
        h--;
      }
    }
    return true;
  }
};
void solve() {
  vector<string> tc = {"A man, a plan, a canal: Panama", "race a car"};
  Solution s;
  for (auto &i : tc) {
    cout << boolalpha << s.isPalindrome(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
