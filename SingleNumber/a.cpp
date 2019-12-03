// Single Number

// Given a non-empty array of integers, every element appears twice except for
// one. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you implement
// it without using extra memory?

// Example 1:

// Input: [2,2,1]
// Output: 1
// Example 2:

// Input: [4,1,2,1,2]
// Output: 4

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

class SolutionHM {
 public:
  int singleNumber(vector<int> &a) {
    unordered_map<int, int> m;
    for (auto &i : a) {
      m[i]++;
    }
    int n = -1;
    for (auto &i : m) {
      if (i.second == 1) {
        n = i.first;
        break;
      }
    }
    return n;
  }
};
class SolutionSort {
 public:
  int singleNumber(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 1; i < n; i += 2) {
      if (a[i] != a[i - 1]) {
        return a[i - 1];
      }
    }
    return a[n - 1];
  }
};
class SolutionXOR {
 public:
  int singleNumber(vector<int> &a) {
    int num = 0;
    for (auto &i : a) {
      num ^= i;
    }
    return num;
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 1, 2}, {2, 2, 1}, {1}};
  SolutionXOR s;
  for (auto &i : tc) {
    cout << s.singleNumber(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
