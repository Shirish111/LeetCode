// Basic Calculator II

// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, /
// operators and empty spaces . The integer division should truncate toward
// zero.

// Example 1:

// Input: "3+2*2"
// Output: 7
// Example 2:

// Input: " 3/2 "
// Output: 1
// Example 3:

// Input: " 3+5 / 2 "
// Output: 5
// Note:

// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

// Tags: expression_parsing, stack, interview
// Difficulty: Hard
// Status: Done

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    Postfix object;
    object.set_postfix(object.infix_to_postfix(s));
    return object.evaluate();
  }
  enum Type { OPERATOR = 1, OPERAND, PARENTHESIS, END_OF_STRING, ERROR };
  class Postfix {
    string postfix;

   public:
    Postfix() {}
    Postfix(string &postfix) : postfix(postfix) {}
    void set_postfix(string s) { postfix = s; }
    string get_postfix() { return postfix; }
    string infix_to_postfix(string &s) const {
      string result;
      Tokenizer tokenizer(s);
      Operator operator_object;
      stack<char> operators;
      Token token;

      while ((token = tokenizer.getNextToken()).type != END_OF_STRING) {
        // token.print_token();
        if (token.type == OPERAND) {
          result.append(token.value + " ");
        } else if (token.type == OPERATOR) {
          while (!operators.empty() && operators.top() != '(' &&
                 operator_object.is_higher_precedence(operators.top(),
                                                      token.value[0])) {
            result.append(1, operators.top());
            operators.pop();
          }
          operators.push(token.value[0]);
        } else {
          if (token.value[0] == '(') {
            operators.push('(');
            continue;
          }
          while (!operators.empty()) {
            if (operators.top() == '(') {
              operators.pop();
              break;
            }
            result.append(1, operators.top());
            operators.pop();
          }
        }
      }
      while (!operators.empty()) {
        result.append(1, operators.top());
        operators.pop();
      }
      return result;
    }
    int evaluate() {
      Tokenizer tokenizer(postfix);
      Operator operator_object;
      Token token;
      stack<int> num;
      stack<int> op;
      while ((token = tokenizer.getNextToken()).type != END_OF_STRING) {
        // token.print_token();
        if (token.type == OPERAND) {
          num.push(stoi(token.value));
        } else {
          int n2 = num.top();
          num.pop();
          int n1 = num.top();
          num.pop();
          num.push(operator_object.apply(n1, n2, token.value[0]));
        }
      }
      int ans = num.top();
      num.pop();
      return ans;
    }
  };
  struct Token {
    string value;
    Type type;
    void print_token() {
      if (type == OPERATOR) {
        cout << "OPERATOR: " << value << "\n";
      } else if (type == OPERAND) {
        cout << "OPERAND: " << value << "\n";
      } else if (type == PARENTHESIS) {
        cout << "PARENTHESIS: " << value << "\n";
      } else {
        cout << "END OF STRING: " << value << "\n";
      }
    }
  };
  class Operator {
   public:
    int apply(int n1, int n2, char op) {
      switch (op) {
        case '+':
          return n1 + n2;
        case '-':
          return n1 - n2;
        case '*':
          return n1 * n2;
        case '/':
          return n1 / n2;
        case '%':
          return n1 % n2;
        case '^':
          return (int)pow(n1, n2);
      }
      return 0;
    }
    int get_precedence(char op) {
      switch (op) {
        case '+':
        case '-':
          return 1;
        case '*':
        case '%':
        case '/':
          return 2;
        case '^':
          return 3;
      }
      return 0;
    }
    bool is_higher_precedence(char op1, char op2) {
      int p1 = get_precedence(op1), p2 = get_precedence(op2);
      if ((op1 == '^' && op2 == '^') || op1 == '(') {
        return false;
      }
      return p1 >= p2;
    }
  };
  class Tokenizer {
    string s;
    int n;
    int u;

   public:
    Tokenizer(string &s) : s(s) {
      n = s.length();
      u = 0;
    }
    Token operand() {
      Token token;
      token.type = OPERAND;
      int beg = u;
      u++;
      while (u < n) {
        if (!isdigit(s[u])) {
          break;
        }
        u++;
      }
      token.value = s.substr(beg, u - beg);
      return token;
    }
    Token end_of_string() {
      Token token;
      token.type = END_OF_STRING;
      token.value = "End of string reached";
      return token;
    }
    Token getNextToken() {
      while (u < n && s[u] == ' ') {  // Ignore whitespace
        u++;
      }
      if (u >= n) {  // Boundary Check
        return end_of_string();
      }
      if (isdigit(s[u])) {  // Number
        return operand();
      }
      if (s[u] == '(' || s[u] == ')') {  // Parenthesis
        return parenthesis();
      }
      return token_operator();  // Operator
    }
    Token parenthesis() {
      Token token;
      token.type = PARENTHESIS;
      token.value = s.substr(u, 1);
      u++;
      return token;
    }
    Token token_operator() {
      Token token;
      token.type = OPERATOR;
      token.value = s.substr(u, 1);
      u++;
      return token;
    }
  };
};
void solve() {
  vector<string> tc = {"3+2*2", " 3/2 ", " 3+5 / 2 "};
  Solution s;
  for (auto &i : tc) {
    cout << s.calculate(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
