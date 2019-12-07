// Evaluate Reverse Polish Notation

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another
// expression.

// Note:

// Division between two integers should truncate toward zero.
// The given RPN expression is always valid. That means the expression would
// always evaluate to a result and there won't be any divide by zero operation.
// Example 1:

// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
// Output: 22
// Explanation:
//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22

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
  stack<int> s;
  void push_result(char c) {
    int num2 = s.top();
    s.pop();
    int num1 = s.top();
    s.pop();
    s.push(calc(num1, num2, c));
  }
  int calc(int num1, int num2, char c) {
    switch (c) {
      case '+':
        return num1 + num2;
      case '-':
        return num1 - num2;
      case '*':
        return num1 * num2;
      default:
        return num1 / num2;
    }
  }
  int evalRPN(vector<string>& tokens) {
    for (auto& token : tokens) {
      if (isOperator(token)) {
        push_result(token[0]);
      } else {
        s.push(stoi(token));
      }
    }
    int ans = s.top();
    s.pop();
    return ans;
  }
  bool isOperator(string& token) {
    if (token.length() != 1) {
      return false;
    }
    char c = token[0];
    if (c == '/' || c == '+' || c == '-' || c == '*') {
      return true;
    }
    return false;
  }
};
void solve() {
  vector<vector<string>> tc = {
      {"2", "1", "+", "3", "*"},
      {"4", "13", "5", "/", "+"},
      {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}};
  Solution s;
  for (auto& i : tc) {
    cout << s.evalRPN(i) << "\n";
  }
}
int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
