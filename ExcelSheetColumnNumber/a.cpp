// Excel Sheet Column Number

// Given a column title as appear in an Excel sheet, return its corresponding
// column number.

// For example:

//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28
//     ...
// Example 1:

// Input: "A"
// Output: 1
// Example 2:

// Input: "AB"
// Output: 28
// Example 3:

// Input: "ZY"
// Output: 701

// Tags: excel

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int titleToNumber(string s) {
    int ans = 0;
    long long num = 1;
    for_each(s.rbegin(), s.rend(), [&](char c) {
      ans += ((c - 'A') + 1) * num;
      num *= 26;
    });
    return ans;
  }
};
void solve() {
  vector<string> tc = {"A", "AB", "ZY"};
  Solution s;
  for (auto &i : tc) {
    cout << s.titleToNumber(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
