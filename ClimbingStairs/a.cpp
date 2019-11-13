// Climbing Stairs

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?

// Note: Given n will be a positive integer.

// Example 1:

// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:

// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

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
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
};
// DP Top Down
class SolutionDPTD {
 public:
  int climbStairs(int n) {
    vector<int> dp(max(3, n + 1), -1);
    dp[1] = 1;
    dp[2] = 2;
    return solve(dp, n);
  }
  int solve(vector<int> &dp, int i) {
    if (dp[i] != -1) {
      return dp[i];
    }
    dp[i] = solve(dp, i - 1) + solve(dp, i - 2);
    return dp[i];
  }
};
// DP Bottom Up
class SolutionDPBU {
 public:
  int climbStairs(int n) {
    vector<int> dp(max(3, n + 1), -1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
// Fibonacci Number
class SolutionFib {
 public:
  int climbStairs(int n) {
    int a = 2, b = 1;
    if (n == 1) {
      return b;
    } else if (n == 2) {
      return a;
    }
    for (int i = 3; i <= n; i++) {
      int t = a;
      a = a + b;
      b = t;
    }
    return a;
  }
};
// Binets Method
class SolutionBinet {
 public:
  long long climbStairs(long long n) { return fib(n); }
  long long fib(long long n) { return matpow(n - 1); }
  long long matpow(long long n) {
    array<array<long long, 2>, 2> mat = {array<long long, 2>{1, 1},
                                         array<long long, 2>{1, 0}};
    array<array<long long, 2>, 2> ans = {array<long long, 2>{1, 1},
                                         array<long long, 2>{1, 0}};
    while (n) {
      if (n & 1) {
        ans = multiply(ans, mat);
      }
      mat = multiply(mat, mat);
      n >>= 1;
    }
    return ans[0][0];
  }
  array<array<long long, 2>, 2> multiply(array<array<long long, 2>, 2> &a,
                                         array<array<long long, 2>, 2> &b) {
    array<array<long long, 2>, 2> c = {array<long long, 2>{0, 0},
                                       array<long long, 2>{0, 0}};
    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < 2; j++) {
        for (long long k = 0; k < 2; k++) {
          c[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    return c;
  }
};
// Fibonacci Formula
class SolutionFormula {
 public:
  int climbStairs(int n) {
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    return (int)(fibn / sqrt5);
  }
};
void solve() {
  vector<int> tc = {1, 2, 3, 4, 5, 35};
  SolutionFormula s;
  for (auto &i : tc) {
    cout << i << " stairs = " << s.climbStairs(i) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
