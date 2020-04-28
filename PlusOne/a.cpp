// Plus One

// Given a non-empty array of digits representing a non-negative integer, plus
// one to the integer.

// The digits are stored such that the most significant digit is at the head of
// the list, and each element in the array contain a single digit.

// You may assume the integer does not contain any leading zero, except the
// number 0 itself.

// Example 1:

// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Example 2:

// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.

// Tags: miscellaneous, number

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& a) {
    vector<int> v;
    int carry = 1;
    for_each(a.rbegin(), a.rend(), [&](int c) {
      int sm = c + carry;
      v.push_back(sm % 10);
      carry = sm / 10;
    });
    if (carry > 0) {
      v.push_back(carry);
    }
    reverse(v.begin(), v.end());
    return v;
  }
};
void solve() {
  vector<vector<int>> tc = {{1, 2, 3}, {4, 3, 2, 1}, {9, 9, 9, 9}, {0}};
  Solution s;
  for (auto& i : tc) {
    cout << "Original: ";
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    vector<int> ans = s.plusOne(i);
    cout << "PlusOne: ";
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
