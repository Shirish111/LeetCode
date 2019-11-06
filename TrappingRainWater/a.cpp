// Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.

// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In
// this case, 6 units of rain water (blue section) are being trapped. Thanks
// Marcos for contributing this image!

// Example:

// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

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

class SolutionBF {
 public:
  // Brute Force
  int trap(vector<int>& a) {
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
      int max_left = a[i], max_right = a[i];
      for (int j = i - 1; j >= 0; j--) {
        max_left = max(max_left, a[j]);
      }
      for (int j = i + 1; j < n; j++) {
        max_right = max(max_right, a[j]);
      }
      ans += min(max_left, max_right) - a[i];
    }
    return ans;
  }
};
class SolutionDP {
 public:
  // DP
  int trap(vector<int>& a) {
    int ans = 0, n = a.size();
    vector<int> max_left(n), max_right(n);
    max_left[0] = a[0];
    max_right[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
      max_left[i] = max(max_left[i - 1], a[i]);
      max_right[n - i - 1] = max(max_right[n - i], a[n - i - 1]);
    }
    for (int i = 0; i < n; i++) {
      ans += min(max_left[i], max_right[i]) - a[i];
    }
    return ans;
  }
};
class SolutionStk {
 public:
  // Using stack
  int trap(vector<int>& a) {
    int ans = 0, cur = 0, n = a.size();
    stack<int> stk;
    while (cur < n) {
      while (!stk.empty() && a[cur] > a[stk.top()]) {
        int top = stk.top();
        stk.pop();
        if (stk.empty()) {
          break;
        }
        int dist = cur - stk.top() - 1;
        int height = min(a[cur], a[stk.top()]) - a[top];
        ans += dist * height;
      }
      stk.push(cur++);
    }
    return ans;
  }
};
class Solution2p {
 public:
  // Two pointers
  int trap(vector<int>& a) {
    int ans = 0, left = 0, n = a.size(), left_max = 0;
    int right = n - 1, right_max = 0;
    while (left < right) {
      if (a[left] < a[right]) {
        if (a[left] < left_max) {
          ans += left_max - a[left];
        } else {
          left_max = a[left];
        }
        left++;
      } else {
        if (a[right] < right_max) {
          ans += right_max - a[right];
        } else {
          right_max = a[right];
        }
        right--;
      }
    }
    return ans;
  }
};
void solve() {
  vector<vector<int>> tc = {{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}};
  Solution2p s;
  for (auto& i : tc) {
    cout << s.trap(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
