// Count Primes

// Count the number of prime numbers less than a non-negative number, n.

// Example:

// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// Tags: prime

#include <bits/stdc++.h>
using namespace std;

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
