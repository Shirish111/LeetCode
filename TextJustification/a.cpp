// Text Justification

// Given an array of words and a width maxWidth, format the text such that each
// line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line do not divide evenly between words, the empty
// slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is
// inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters
// only. Each word's length is guaranteed to be greater than 0 and not exceed
// maxWidth. The input array words contains at least one word. Example 1:

// Input:
// words = ["This", "is", "an", "example", "of", "text", "justification."]
// maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:

// Input:
// words = ["What","must","be","acknowledgment","shall","be"]
// maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall be",
//              because the last line must be left-justified instead of
//              fully-justified. Note that the second line is also
//              left-justified becase it contains only one word.
// Example 3:

// Input:
// words =
// ["Science","is","what","we","understand","well","enough","to","explain",
//          "to","a","computer.","Art","is","everything","else","we","do"]
// maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

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
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    int w = 0;
    vector<string> ans;
    for (int i = w; i < n; i = w) {
      int len = -1;  // Since the first space has to be ignored
      while (w < n && len + words[w].length() + 1 <= maxWidth) {
        len += words[w++].length() + 1;
      }
      int evenlyDistSpaces = 1;  // Default single space between each word
      int numGaps = w - i - 1;   // Number of gaps = words in current line - 1
      int extraspaces = 0;
      if (numGaps > 0 &&
          w != n) {  // Multiple words in current line and not the last line
        evenlyDistSpaces = (maxWidth - len) / numGaps +
                           1;  // plus 1 for default space between words
        extraspaces = (maxWidth - len) % numGaps;
      }
      string line(words[i]);
      for (int j = i + 1; j < w; j++) {
        line.append(evenlyDistSpaces, ' ');
        if (extraspaces > 0) {
          line.append(1, ' ');
          extraspaces--;
        }
        line.append(words[j]);
      }
      int remaining = maxWidth - line.length();
      if (remaining > 0) {  // Last line or single word on current line
        line.append(remaining, ' ');
      }
      ans.push_back(line);
    }
    return ans;
  }
};
void solve() {
  vector<pair<vector<string>, int>> tc = {
      {{"This", "is", "an", "example", "of", "text", "justification."}, 16},
      {{"What", "must", "be", "acknowledgment", "shall", "be"}, 16},
      {{"Science", "is", "what", "we", "understand", "well", "enough", "to",
        "explain", "to", "a", "computer.", "Art", "is", "everything", "else",
        "we", "do"},
       20},
      {{""}, 10}};
  Solution s;
  for (auto& i : tc) {
    vector<string> ans = s.fullJustify(i.first, i.second);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, "\n"));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
