// Repeated DNA Sequences

// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
// for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
// identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that
// occur more than once in a DNA molecule.

// Example:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

// Output: ["AAAAACCCCC", "CCCCCAAAAA"]

// Tags: bit_manipulation, bitmasks, hashing

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> seen;
    vector<string> res;
    vector<int> charHash(255);
    charHash['A'] = 0;
    charHash['C'] = 1;
    charHash['G'] = 2;
    charHash['T'] = 3;
    int n = s.length();
    int v = 0;
    for (int i = 0; i < 9; i++) {
      v = v << 2;
      v |= charHash[s[i]];
    }
    for (int i = 9; i < n; ++i) {
      v = v << 2;
      v |= charHash[s[i]];
      v &= 0xfffff;
      seen[v]++;
      if (seen[v] == 2) {
        res.push_back(s.substr(i - 9, 10));
      }
    }
    return res;
  }
};
void solve() {
  vector<string> tc = {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"};
  Solution s;
  for (auto &i : tc) {
    vector<string> ans = s.findRepeatedDnaSequences(i);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
