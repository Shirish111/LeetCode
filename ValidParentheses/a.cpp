// Valid Parentheses

// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.

// Example 1:

// Input: "()"
// Output: true
// Example 2:

// Input: "()[]{}"
// Output: true
// Example 3:

// Input: "(]"
// Output: false
// Example 4:

// Input: "([)]"
// Output: false
// Example 5:

// Input: "{[]}"
// Output: true

// Tags: parenthesis, array, stack

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s == "") return true;
    unordered_map<char, char> a;
    int opp[256];
    opp['('] = ')';
    opp['{'] = '}';
    opp['['] = ']';
    stack<char> stk;
    bool valid = true;
    for (const auto &i : s) {
      if (i == '(') {
        stk.push(')');
      } else if (i == '{') {
        stk.push('}');
      } else if (i == '[') {
        stk.push(']');
      } else {
        if (stk.empty() || stk.top() != i) {
          valid = false;
          break;
        }
        stk.pop();
      }
    }
    return valid && stk.empty();
  }
};

void solve() {
  vector<string> tc = {"", "()", "()[]{}", "(]", "([)]", "{[]}"};
  Solution solution;
  for (const auto &i : tc) {
    cout << i << boolalpha << " " << solution.isValid(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
