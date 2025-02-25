// Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// Tags: parenthesis, recursion, back_tracking

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
 public:
  // BackTracking
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    char s[2 * n + 1];
    s[2 * n] = '\0';
    f(ans, s, 0, 0, 0, n);
    return ans;
  }
  void f(vector<string>& ans, char* s, int op, int cp, int i, int n) {
    if (i == 2 * n) {
      ans.push_back(string(s));
      return;
    }
    if (op < n) {
      s[i] = '(';
      f(ans, s, op + 1, cp, i + 1, n);
    }
    if (cp < op) {
      s[i] = ')';
      f(ans, s, op, cp + 1, i + 1, n);
    }
  }
};

void solve() {
  vector<int> tc = {3};
  Solution solution;
  for (const auto& i : tc) {
    for (const auto& j : solution.generateParenthesis(i)) {
      cout << j << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
