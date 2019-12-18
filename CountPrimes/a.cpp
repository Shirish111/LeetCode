// Count Primes

// Count the number of prime numbers less than a non-negative number, n.

// Example:

// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

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
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {
        cnt++;
        int j = i << 1;
        while (j < n) {
          isPrime[j] = false;
          j += i;
        }
      }
    }
    return cnt;
  }
};
void solve() {
  vector<int> tc = {2, 10, 3, 17, 19, 20};
  Solution s;
  for (auto &i : tc) {
    cout << s.countPrimes(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
