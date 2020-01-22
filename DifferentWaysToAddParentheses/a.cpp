// Different Ways to Add Parentheses

// Given a string of numbers and operators, return all possible results from
// computing all the different possible ways to group numbers and operators. The
// valid operators are +, - and *.

// Example 1:

// Input: "2-1-1"
// Output: [0, 2]
// Explanation:
// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Example 2:

// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation:
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  unordered_map<string, vector<int>> cache;
  vector<int> diffWaysToCompute(string a) {
    vector<int> res;
    int n = a.length();
    for (int i = 0; i < n; ++i) {
      if (a[i] == '*' || a[i] == '+' || a[i] == '-') {
        string part1 = a.substr(0, i);
        string part2 = a.substr(i + 1);
        vector<int> ans1 = getAns(part1);
        vector<int> ans2 = getAns(part2);
        for (auto &n1 : ans1) {
          for (auto &n2 : ans2) {
            res.push_back(apply_operator(n1, n2, a[i]));
          }
        }
      }
    }
    if (res.size() == 0) {
      if (a.size() == 0) {
        res.push_back(0);
      } else {
        res.push_back(stoi(a));
      }
    }
    cache[a] = res;
    return res;
  }
  int apply_operator(int n1, int n2, char op) {
    switch (op) {
      case '+':
        return n1 + n2;
      case '*':
        return n1 * n2;
      default:
        return n1 - n2;
    }
  }
  vector<int> getAns(string &a) {
    if (cache.find(a) != cache.end()) {
      return cache[a];
    }
    vector<int> ans = diffWaysToCompute(a);
    cache[a] = ans;
    return ans;
  }
};
void solve() {
  vector<string> tc = {"2-1-1", "2*3-4*5"};
  Solution s;
  for (auto &i : tc) {
    vector<int> ans = s.diffWaysToCompute(i);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
