// Sort Colors

// Given an array with n objects colored red, white or blue, sort them in-place
// so that objects of the same color are adjacent, with the colors in the order
// red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white,
// and blue respectively.

// Note: You are not suppose to use the library's sort function for this
// problem.

// Example:

// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Follow up:

// A rather straight forward solution is a two-pass algorithm using counting
// sort. First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's. Could
// you come up with a one-pass algorithm using only constant space?

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

// Using library function
class SolutionLib {
 public:
  void sortColors(vector<int>& a) { sort(a.begin(), a.end()); }
};
// Using Frequency Count
class SolutionFreq {
 public:
  void sortColors(vector<int>& a) {
    int n = a.size();
    int freq[3] = {0};
    for (auto& i : a) {
      freq[i]++;
    }
    int k = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < freq[i]; j++) {
        a[k++] = i;
      }
    }
  }
};
// Using Counting Sort
class SolutionCS {
 public:
  void sortColors(vector<int>& a) {
    vector<int> b(a);
    int n = a.size();
    vector<int> c(3);  // Since numbers are in the range 0..2
    for (int i = 0; i < n; i++) {
      c[a[i]]++;
    }
    for (int i = 1; i < 3; i++) {
      c[i] += c[i - 1];
    }
    for (int i = 0; i < n; i++) {
      a[--c[b[i]]] = b[i];
    }
  }
};
// Using Swapping Technique
// Moving Zeroes to left and 2's to right
class SolutionSwap {
 public:
  void sortColors(vector<int>& a) {
    int n = a.size();
    int fp = 0, bp = n - 1;
    for (int i = 0; i < n; i++) {
      while (i < bp && a[i] == 2) swap(a[i], a[bp--]);
      while (i > fp && a[i] == 0) swap(a[i], a[fp++]);
    }
  }
};
void solve() {
  vector<vector<int>> tc = {{2, 0, 2, 1, 1, 0}};
  SolutionSwap s;
  for (auto& i : tc) {
    s.sortColors(i);
    copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
