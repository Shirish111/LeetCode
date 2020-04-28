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

// Tags: palindrome, array

#include <bits/stdc++.h>
using namespace std;

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
