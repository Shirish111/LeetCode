// Reverse Words in a String

// Given an input string, reverse the string word by word.

// Example 1:

// Input: "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing
// spaces. Example 3:

// Input: "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single
// space in the reversed string.

// Note:

// A word is defined as a sequence of non-space characters.
// Input string may contain leading or trailing spaces. However, your reversed
// string should not contain leading or trailing spaces. You need to reduce
// multiple spaces between two words to a single space in the reversed string.

// Follow up:

// For C programmers, try to solve it in-place in O(1) extra space.

// Tags: string_manipulation, reverse

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseWords(string &s) {
    bool fnd = false;
    for (auto &i : s) {
      if (i != ' ') {
        fnd = true;
      }
    }
    if (!fnd) {
      return "";
    }
    reverse(s.begin(), s.end());
    stringstream ss(s);
    string result;
    ss >> s;
    result.append(s);
    reverse(result.begin(), result.end());
    while (ss >> s) {
      reverse(s.begin(), s.end());
      result.append(" " + s);
    }
    return result;
  }
};
void solve() {
  vector<string> tc = {"the sky is blue", "  hello world!  ",
                       "a good   example", "  "};
  Solution s;
  for (auto &i : tc) {
    string ans = s.reverseWords(i);
    cout << ans.length() << ans << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
