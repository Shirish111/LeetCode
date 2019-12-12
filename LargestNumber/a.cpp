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
