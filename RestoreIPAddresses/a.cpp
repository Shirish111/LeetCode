// Restore IP Addresses

// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.

// Example:

// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]

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
  int n;
  vector<string> ans;
  vector<string> v;
  vector<string> restoreIpAddresses(string &s) {
    ans.clear();
    v.clear();
    n = s.length();
    if (n == 0 || n < 4) {
      return ans;
    }
    backtrack(s, 0, 0);
    return ans;
  }
  void backtrack(string &s, int k, int beg) {
    if (k == 4) {
      if (beg == n) {
        ans.push_back(get_string(v));
      }
      return;
    }
    if (beg == n) {
      return;
    }
    for (int i = 1; i <= 3 && beg + i <= n; i++) {
      string s1 = s.substr(beg, i);
      if (isValid(s1, i)) {
        v.push_back(s1);
        backtrack(s, k + 1, beg + i);
        v.pop_back();
      }
    }
  }
  bool isValid(string &s, int len) {
    if (len == 1) {
      return true;
    }
    if (s[0] == '0') {
      return false;
    }
    if (len == 2) {
      return true;
    }
    if (((s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0') > 255) {
      return false;
    }
    return true;
  }
  string get_string(vector<string> &v) {
    string ans;
    ans.append(v[0]);
    for (int i = 1; i < 4; i++) {
      ans.append(1, '.');
      ans.append(v[i]);
    }
    return ans;
  }
};
void solve() {
  vector<string> tc = {"25525511135", "0000", "010010", "3923156"};
  Solution s;
  for (auto &i : tc) {
    cout << i << "\n";
    vector<string> a = s.restoreIpAddresses(i);
    copy(a.begin(), a.end(), ostream_iterator<string>(cout, " "));
    cout << "\n";
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
