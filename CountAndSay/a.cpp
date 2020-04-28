// Count and Say

// The count-and-say sequence is the sequence of integers with the first five
// terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.

// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
// count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"

// Tags: miscellaneous

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string res = "1";
    while (--n) {
      res = build(res);
    }
    return res;
  }
  string build(string &s) {
    char c = s[0];
    int cnt = 1;
    int n = s.length();
    string res;
    for (int i = 1; i < n; i++) {
      if (s[i] == c) {
        cnt++;
      } else {
        res.append(1, cnt + '0');
        res.append(1, c);
        c = s[i];
        cnt = 1;
      }
    }
    res.append(1, cnt + '0');
    res.append(1, c);
    return res;
  }
};
void solve() {
  vector<int> tc = {0, 1, 2, 3, 4, 5};
  Solution solution;
  for (auto &i : tc) {
    cout << solution.countAndSay(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
