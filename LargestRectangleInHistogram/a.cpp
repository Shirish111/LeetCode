// Largest Rectangle in Histogram

// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.

// Above is a histogram where width of each bar is 1, given height =
// [2,1,5,6,2,3].

// The largest rectangle is shown in the shaded area, which has area = 10 unit.

// Example:

// Input: [2,1,5,6,2,3]
// Output: 10

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

// Brute Force
class SolutionBF {
 public:
  int largestRectangleArea(vector<int>& a) {
    int n = a.size();
    if (n == 0) {
      return 0;
    }
    int mx = 0, min_ht;
    for (int i = 0; i < n; i++) {
      min_ht = a[i];
      for (int j = i; j < n; j++) {
        min_ht = min(min_ht, a[j]);
        mx = max(mx, min_ht * (j - i + 1));
      }
    }
    return mx;
  }
};
class SolutionDP {
 public:
  int largestRectangleArea(vector<int>& a) {
    int n = a.size();
    if (n == 0) {
      return 0;
    }
    vector<long long> al(n), ar(n);
    al[0] = -1;
    ar[n - 1] = n;
    for (int i = 1; i < n; i++) {
      int p = i - 1;
      while (p >= 0 && a[p] >= a[i]) {
        p = al[p];
      }
      al[i] = p;
    }
    for (int i = n - 2; i >= 0; i--) {
      int p = i + 1;
      while (p < n && a[p] >= a[i]) {
        p = ar[p];
      }
      ar[i] = p;
    }
    long long mx = 0;
    for (int i = 0; i < n; i++) {
      mx = max(mx, (a[i] * (ar[i] - al[i] - 1)));
    }
    return mx;
  }
};
// Using Stack
class Solution {
 public:
  int largestRectangleArea(vector<int>& a) {
    int n = a.size();
    int mx = 0;
    stack<int> s;
    for (int i = 0; i <= n; i++) {
      int ht = i == n ? 0 : a[i];  // Current height
      if (s.empty() || ht >= a[s.top()]) {
        s.push(i);
      } else {
        int top_ht = a[s.top()];
        s.pop();                                      // Pop top index
        int width = s.empty() ? i : i - s.top() - 1;  // Calculate width
        mx = max(mx, top_ht * width);
        i--;
      }
    }
    return mx;
  }
};
void solve() {
  vector<vector<int>> tc = {{2, 1, 5, 6, 2, 3}};
  Solution s;
  for (auto& i : tc) {
    cout << s.largestRectangleArea(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
