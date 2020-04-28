// Largest Number

// Given a list of non negative integers, arrange them such that they form the
// largest number.

// Example 1:

// Input: [10,2]
// Output: "210"
// Example 2:

// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string instead of
// an integer.

// Tags: miscellaneous, number

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string largestNumber(vector<int> &a) {
    string ans;
    vector<string> b;
    for_each(a.begin(), a.end(), [&](auto &i) { b.push_back(to_string(i)); });
    sort(b.begin(), b.end(),
         [&](auto &x, auto &y) -> bool { return x + y > y + x; });
    for_each(b.begin(), b.end(), [&](auto &i) { ans.append(i); });
    size_t i = 0;
    while (i < ans.length()) {
      if (ans[i] != '0') {
        return ans.substr(i);
      }
      i++;
    }
    return "0";
  }
};
void solve() {
  vector<vector<int>> tc = {{10, 2},
                            {3, 30, 34, 5, 9},
                            {3, 92, 99, 97, 98, 25, 26, 24},
                            {12, 121},
                            {0, 0}};
  Solution s;
  for (auto &i : tc) {
    cout << s.largestNumber(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
