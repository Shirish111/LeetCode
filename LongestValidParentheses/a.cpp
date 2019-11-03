// Longest Valid Parentheses

// Given a string containing just the characters '(' and ')', find the length of
// the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:

// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"

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

class Solution1 {
 public:
  // Brute force Time: O(n^3), Space: O(n)
  int longestValidParentheses(string &s) {
    int mx = 0;
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j += 2) {
        if (isValid(s, i, j)) {
          mx = max(mx, j - i + 1);
        }
      }
    }
    return mx;
  }
  bool isValid(string &s, int i, int j) {
    stack<char> stk;
    while (i <= j) {
      if (s[i] == '(') {
        stk.push('(');
      } else if (!stk.empty()) {
        stk.pop();
      } else {
        return false;
      }
      i++;
    }
    return stk.empty();
  }
};
class Solution2 {
 public:
  // Dynamic Programming TC: O(n), SC: O(n)
  int longestValidParentheses(string &s) {
    int n = s.length();
    if (n <= 1) {
      return 0;
    }
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = (s[0] == '(') && (s[1] == ')') ? 2 : 0;
    for (int i = 2; i < n; i++) {
      if (s[i] == '(') {
        dp[i] = 0;
      } else {
        if (s[i - 1] == '(') {
          dp[i] = dp[i - 2] + 2;
        } else {
          int opp_ind = i - dp[i - 1] - 1;
          if (opp_ind >= 0 && s[opp_ind] == '(') {
            dp[i] = dp[i - 1] + 2;
            if (opp_ind > 0) {
              dp[i] += dp[opp_ind - 1];
            }
          } else {
            dp[i] = 0;
          }
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
class Solution3 {
 public:
  // Using stack TC: O(n), SC: O(n)
  int longestValidParentheses(string &s) {
    int n = s.length();
    if (n <= 1) {
      return 0;
    }
    stack<int> stk;
    stk.push(-1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        stk.pop();
        if (stk.empty()) {
          stk.push(i);
        } else {
          mx = max(mx, i - stk.top());
        }
      }
    }
    return mx;
  }
};
class Solution {
 public:
  // USing two counters approach O(n)
  int longestValidParentheses(string &s) {
    int n = s.length();
    if (n <= 1) {
      return 0;
    }
    int mx = 0;
    int left, right;
    left = right = 0;
    for (int i = 0; i < n; i++) {  // '(' are less equal ')' eg ())()
      if (s[i] == '(') {
        left++;
      } else {
        right++;
      }
      if (left == right) {
        mx = max(mx, 2 * right);
      } else if (right > left) {
        left = right = 0;
      }
    }
    left = right = 0;
    for (int i = n - 1; i >= 0; i--) {  // '(' are greater equal ')' eg ((()
      if (s[i] == '(') {
        left++;
      } else {
        right++;
      }
      if (left == right) {
        mx = max(mx, 2 * left);
      } else if (left > right) {
        left = right = 0;
      }
    }
    return mx;
  }
};
void solve() {
  vector<string> tc = {"(()", ")()())", "())()", "()(())", "(()())"};
  Solution solution;
  for (auto &i : tc) {
    cout << solution.longestValidParentheses(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
