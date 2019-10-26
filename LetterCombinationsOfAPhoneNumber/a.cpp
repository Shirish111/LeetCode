// Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given
// below. Note that 1 does not map to any letters.

// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be
// in any order you want.

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
  int n;
  vector<string> v = {"",    "",    "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<int> vl = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
  string ans;
  vector<string> letterCombinations(string &s) {
    vector<string> vans;
    if (s == "") {
      return vans;
    }
    n = s.length();
    ans.resize(n);
    f(vans, s, 0);
    return vans;
  }
  void f(vector<string> &vans, string &s, int i) {
    if (i == n) {
      vans.push_back(ans);
      return;
    }
    for (auto &k : v[s[i] - '0']) {
      ans[i] = k;
      f(vans, s, i + 1);
    }
  }
};
void solve() {
  Solution solution;
  string s1 = "23";
  vector<string> vans = solution.letterCombinations(s1);
  for (const auto &i : vans) {
    cout << i << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
