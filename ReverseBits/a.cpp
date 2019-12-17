// Reverse Bits

// Reverse bits of a given 32 bits unsigned integer.

// Example 1:

// Input: 00000010100101000001111010011100
// Output: 00111001011110000010100101000000
// Explanation: The input binary string 00000010100101000001111010011100
// represents the unsigned integer 43261596, so return 964176192 which its
// binary representation is 00111001011110000010100101000000. Example 2:

// Input: 11111111111111111111111111111101
// Output: 10111111111111111111111111111111
// Explanation: The input binary string 11111111111111111111111111111101
// represents the unsigned integer 4294967293, so return 3221225471 which its
// binary representation is 10111111111111111111111111111111.

// Note:

// Note that in some languages such as Java, there is no unsigned integer type.
// In this case, both input and output will be given as signed integer type and
// should not affect your implementation, as the internal binary representation
// of the integer is the same whether it is signed or unsigned. In Java, the
// compiler represents the signed integers using 2's complement notation.
// Therefore, in Example 2 above the input represents the signed integer -3 and
// the output represents the signed integer -1073741825.

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
  uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0;
    for (int i = 0; i < 32; ++i) {
      m <<= 1;
      m |= (n & 1);
      n >>= 1;
    }
    return m;
  }
};
void solve() {
  vector<uint32_t> tc = {uint32_t(43261596), uint32_t(4294967293)};
  Solution s;
  for (auto &i : tc) {
    cout << s.reverseBits(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
