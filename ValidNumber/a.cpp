// Valid Number

// Validate if a given string can be interpreted as a decimal number.

// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// " -90e3   " => true
// " 1e" => false
// "e3" => false
// " 6e-1" => true
// " 99e2.5 " => false
// "53.5e93" => true
// " --6 " => false
// "-+3" => false
// "95a54e53" => false

// Note: It is intended for the problem statement to be ambiguous. You should
// gather all requirements up front before implementing one. However, here is a
// list of characters that can be in a valid decimal number:

// Numbers 0-9
// Exponent - "e"
// Positive/negative sign - "+"/"-"
// Decimal point - "."
// Of course, the context of these characters also matters in the input.

// Update (2015-02-10):
// The signature of the C++ function had been updated. If you still see your
// function signature accepts a const char * argument, please click the reload
// button to reset your code definition.

// Tags: miscellaneous, number

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool pf, ef, sf, spf;
  bool checkSign(char c) { return (c == '+' || c == '-') && !sf; }
  bool checkDot(char c) { return c == '.' && !pf; }
  bool checkExp(char c) { return c == 'e' && !ef; }
  bool checkSpace(char c) { return c == ' ' && !spf; }
  bool isNumber(string s) {
    int n = s.length();
    int state = 0;
    ef = false, pf = false, spf = false;
    for (auto &c : s) {
      switch (state) {
        case 0:
          // Initial State
          if (checkSpace(c)) {
            continue;  // Ignore space
          } else if (checkSign(c)) {
            state = 1;  // Need dot or number
            sf = true;
          } else if (isdigit(c)) {
            state = 3;  // Number started
          } else if (checkDot(c)) {
            pf = true;
            sf = true;
            state = 2;  // Number needed
          } else {
            state = -1;  // Invalid state
          }
          spf = true;
          break;
        case 1:
          // After + or -
          if (isdigit(c)) {
            state = 3;  // Number started
          } else if (checkDot(c)) {
            pf = true;
            state = 2;  // Number needed
          } else {
            state = -1;
          }
          break;
        case 2:
          // Number needed
          if (isdigit(c)) {
            state = 3;  // Number started
          } else {
            state = -1;  // Invalid state
          }
          break;
        case 3:
          // Number started
          if (isdigit(c)) {
            continue;
          } else if (checkExp(c)) {
            ef = true;
            pf = true;
            sf = false;
            state = 0;
          } else if (checkDot(c)) {
            pf = true;
            state = 3;
          } else if (c == ' ') {
            state = 4;
          } else {
            state = -1;
          }
          break;
        case 4:
          // Only Spaces
          if (c != ' ') {
            state = -1;
          }
          break;
      }
      if (state == -1) {
        break;
      }
    }
    return state > 2;
  }
};
void solve() {
  vector<pair<string, bool>> tc = {
      {"0", true},    {" 0.1", true},      {"abc", false},    {"1 a", false},
      {"2e10", true}, {" -90e3", true},    {" 1e", false},    {"e3", false},
      {"6e-1", true}, {"99e2.5", false},   {"53.5e93", true}, {" --6", false},
      {"-+3", false}, {"95a54e53", false}, {"1 ", true},      {"1 1", false},
      {".1", true},   {"1.", true},        {".", false},      {"+", false},
      {"-", false},   {"0", true}};
  Solution s;
  for (auto &i : tc) {
    bool ans = s.isNumber(i.first);
    cout << i.first << " Exp: " << i.second << " Res:" << s.isNumber(i.first)
         << "\t" << ((ans == i.second) ? "Passed" : "Failed") << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
