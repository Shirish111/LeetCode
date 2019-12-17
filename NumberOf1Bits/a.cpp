// Number of 1 Bits

// Write a function that takes an unsigned integer and return the number of '1'
// bits it has (also known as the Hamming weight).

// Example 1:

// Input: 00000000000000000000000000001011
// Output: 3
// Explanation: The input binary string 00000000000000000000000000001011 has a
// total of three '1' bits. Example 2:

// Input: 00000000000000000000000010000000
// Output: 1
// Explanation: The input binary string 00000000000000000000000010000000 has a
// total of one '1' bit. Example 3:

// Input: 11111111111111111111111111111101
// Output: 31
// Explanation: The input binary string 11111111111111111111111111111101 has a
// total of thirty one '1' bits.

// Note:

// Note that in some languages such as Java, there is no unsigned integer type.
// In this case, the input will be given as signed integer type and should not
// affect your implementation, as the internal binary representation of the
// integer is the same whether it is signed or unsigned. In Java, the compiler
// represents the signed integers using 2's complement notation. Therefore, in
// Example 3 above the input represents the signed integer -3.

// Follow up:

// If this function is called many times, how would you optimize it?

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
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
      cnt++;
      n &= (n - 1);
    }
    return cnt;
  }
};
void solve() {
  vector<uint32_t> tc = {uint32_t(13), uint32_t(128)};
  Solution s;
  for (auto &i : tc) {
    cout << s.hammingWeight(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
