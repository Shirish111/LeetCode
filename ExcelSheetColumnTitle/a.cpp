// Excel Sheet Column Title

// Given a positive integer, return its corresponding column title as appear in
// an Excel sheet.

// For example:

//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB
//     ...
// Example 1:

// Input: 1
// Output: "A"
// Example 2:

// Input: 28
// Output: "AB"
// Example 3:

// Input: 701
// Output: "ZY"

// Tags: excel

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string convertToTitle(int n) {
    string s;
    while (n) {
      int r = (n - 1) % 26;
      s.append(1, r + 'A');
      n -= r + 1;
      n /= 26;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
void solve() {
  vector<int> tc = {1, 28, 701};
  Solution s;
  for (auto &i : tc) {
    cout << s.convertToTitle(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
