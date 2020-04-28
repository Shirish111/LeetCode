// Add Binary

// Given two binary strings, return their sum (also a binary string).

// The input strings are both non-empty and contains only characters 1 or 0.

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

// Tags: bit_manipulation
// Difficulty: Easy
// Important: Current sum digit = n1 && n2, Current carry = (n1 && n2) ||
// prev_carry && (n1 ^ n2)
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int al = a.length() - 1, bl = b.length() - 1;
    bool c = false;
    while (al >= 0 || bl >= 0) {
      bool n1 = al >= 0 ? a[al--] == '1' : false;
      bool n2 = bl >= 0 ? b[bl--] == '1' : false;
      ans.append(1, (n1 ^ n2 ^ c) + '0');
      c = (n1 && n2) || (c && (n1 ^ n2));
    }
    if (c != 0) {
      ans.append(1, '1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
void solve() {
  vector<pair<string, string>> tc = {{"11", "1"}, {"1010", "1011"}};
  Solution s;
  for (auto &i : tc) {
    cout << i.first << " + " << i.second << " = "
         << s.addBinary(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
