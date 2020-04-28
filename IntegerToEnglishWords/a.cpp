// Integer to English Words

// Convert a non-negative integer to its english words representation. Given
// input is guaranteed to be less than 231 - 1.

// Example 1:

// Input: 123
// Output: "One Hundred Twenty Three"
// Example 2:

// Input: 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:

// Input: 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
// Seven" Example 4:

// Input: 1234567891
// Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven
// Thousand Eight Hundred Ninety One"

// Tags: miscellaneous, recursion, number

#include <bits/stdc++.h>
using namespace std;

class Solution {
  const string P[11] = {"",         "",        "Hundred", "Thousand",
                        "Thousand", "Hundred", "Million", "Million",
                        "Hundred",  "Billion", "Billion"};
  const string Units[10] = {"",     "One", "Two",   "Three", "Four",
                            "Five", "Six", "Seven", "Eight", "Nine"};
  const string W10[10] = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                          "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                          "Eighteen", "Nineteen"};
  const string Tens[10] = {"",      "Twenty",  "Thirty", "Forty",  "Fifty",
                           "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};
  int l;

 public:
  string numberToWords(int num) {
    vector<int> pos = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
    if (num == 0) {
      return "Zero";
    }
    string s = to_string(num);
    l = s.length();
    string ans("");
    bool flag = false;
    for (int i = 0; i < l;) {
      string w1 = getNum(s, i, pos[l - i - 1]);
      i += pos[l - i - 1];
      if (w1.size() > 0) {
        if (flag == false) {
          flag = true;
        } else {
          ans.append(" ");
        }
      }
      ans.append(w1);
    }
    return ans;
  }
  string getNum(const string &s, int i, int k) {
    string num, suffix;
    if (k == 1) {
      return withPower(UnitsToWords(s, i), i);
    } else if (k == 2) {
      return withPower(TensToWords(s, i), i);
    }
    string w1 = withPower(UnitsToWords(s, i), i);
    string w2 = withPower(TensToWords(s, i + 1), i + 1);
    return adjustWords(w1, w2, i, 3);
  }
  string adjustWords(string w1, string w2, int i = 0, int k = 0) {
    if (w1.size() > 0 && w2.size() > 0) {
      return w1 + " " + w2;
    } else if (w1.size() > 0) {
      if (k == 3) {
        return withPower(w1, i + 1);
      }
      return w1;
    }
    return w2;
  }
  string withPower(string &&w, int i) {
    if (w.size() == 0) {
      return "";
    }
    string w2 = P[l - i - 1];
    return adjustWords(w, w2);
  }
  string withPower(string &w, int i) {
    if (w.size() == 0) {
      return "";
    }
    string w2 = P[l - i - 1];
    return adjustWords(w, w2);
  }

  string UnitsToWords(const string &s, int i) { return Units[s[i] - '0']; }
  string TensToWords(const string &s, int i) {
    if (s[i] == '0' && s[i + 1] == '0') {
      return "";
    }
    if (s[i] == '0') {
      return Units[s[i + 1] - '0'];
    }
    if (s[i] == '1') {
      return W10[s[i + 1] - '0'];
    }
    string w1 = Tens[s[i] - '0' - 1];
    string w2 = Units[s[i + 1] - '0'];
    return adjustWords(w1, w2, i, 2);
  }
};

void solve() {
  Solution s;
  // for (int i = 0; i < 25; ++i) {
  //   cout << " i: " << i << ": " << s.numberToWords(i) << "\n";
  // }
  // for (int i = 95; i < 105; ++i) {
  //   cout << " i: " << i << ": " << s.numberToWords(i) << "\n";
  // }
  // for (int i = 195; i < 205; ++i) {
  //   cout << " i: " << i << ": " << s.numberToWords(i) << "\n";
  // }
  vector<int> tc = {300000, 1,         10001,    123,     50140,
                    2300,   719385729, 18375619, 10001010};
  for (auto &i : tc) {
    cout << " i: " << i << ": " << s.numberToWords(i) << "Done\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
