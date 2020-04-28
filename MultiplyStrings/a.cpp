// Multiply Strings

// Given two non-negative integers num1 and num2 represented as strings, return
// the product of num1 and num2, also represented as a string.

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
// Note:

// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0
// itself. You must not use any built-in BigInteger library or convert the
// inputs to integer directly.

// Tags: number, string_manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
 public:
  string multiply(string &a, string &b) {
    if (a == "0" || b == "0") {
      return string("0");
    }
    int l1 = a.length(), l2 = b.length();
    string ans;
    for (int i = l2 - 1; i >= 0; i--) {
      string res = multiply(a, l1, b[i] - '0');
      res.append(l2 - i - 1, '0');
      ans = add(ans, res);
    }
    return ans;
  }
  string multiply(string &s, int n, int num) {
    string ans;
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
      int p = (s[i] - '0') * num + carry;
      carry = p / 10;
      ans.append(1, (p % 10) + '0');
    }
    if (carry > 0) {
      ans.append(1, carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  string add(string &a, string &b) {
    int l1 = a.length(), l2 = b.length();
    string ans;
    int carry = 0;
    int i = l1 - 1, j = l2 - 1;
    while (i >= 0 || j >= 0) {
      int n1 = i >= 0 ? a[i] - '0' : 0;
      int n2 = j >= 0 ? b[j] - '0' : 0;
      int sm = n1 + n2 + carry;
      carry = sm / 10;
      ans.append(1, sm % 10 + '0');
      i--;
      j--;
    }
    if (carry > 0) {
      ans.append(1, carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
class Solution {
 public:
  string multiply(string &a, string &b) {
    int l1 = a.length(), l2 = b.length();
    vector<int> ans(l1 + l2, 0);
    for (int i = l1 - 1; i >= 0; i--) {
      for (int j = l2 - 1; j >= 0; j--) {
        int prod = (a[i] - '0') * (b[j] - '0') + ans[i + j + 1];
        ans[i + j + 1] = prod % 10;
        ans[i + j] += prod / 10;
      }
    }
    return build_string(ans, l1 + l2);
  }
  string build_string(vector<int> &v, int n) {
    char ans[n + 1];
    int p = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (flag) {
        ans[p++] = v[i] + '0';
      } else if (v[i] != 0) {
        flag = true;
        ans[p++] = v[i] + '0';
      }
    }
    ans[p] = '\0';
    return p == 0 ? "0" : ans;
  }
};
void solve() {
  vector<pair<string, string>> tc = {
      {"123", "456"}, {"0", "0"}, {"1", "1"}, {"9", "9"}, {"00", "00"}};
  Solution s;
  for (auto &i : tc) {
    cout << s.multiply(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
