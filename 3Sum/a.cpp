// 3Sum

// Given an array nums of n integers, are there elements a, b, c in nums such
// that a + b + c = 0? Find all unique triplets in the array which gives the sum
// of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

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
  vector<vector<int>> threeSum(vector<int>& a) {
    vector<vector<int>> ans;
    int n = a.size(), fp, bp, sm, target;
    sort(a.begin(), a.end());
    int i = 0;
    while (i < n - 2) {
      target = -a[i];
      fp = i + 1;
      bp = n - 1;
      while (fp < bp) {
        sm = a[fp] + a[bp];
        if (sm == target) {
          ans.push_back(vector<int>({a[i], a[fp], a[bp]}));
          fp++;
          bp--;
          while (fp < bp && a[fp] == a[fp - 1]) fp++;
          while (fp < bp && a[bp] == a[bp + 1]) bp--;
        } else if (sm < target) {
          fp++;
        } else {
          bp--;
        }
      }
      i++;
      while (i < n && a[i] == a[i - 1]) i++;
    }
    return ans;
  }
};
void solve() {
  Solution solution;
  vector<int> a = {0, 0, 0};
  vector<vector<int>> ans = solution.threeSum(a);
  for (int i = 0; i < ans.size(); i++) {
    copy(ans[i].begin(), ans[i].end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
