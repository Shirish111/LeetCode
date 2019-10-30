// 4Sum

// Given an array nums of n integers and an integer target, are there elements
// a, b, c, and d in nums such that a + b + c + d = target? Find all unique
// quadruplets in the array which gives the sum of target.

// Note:

// The solution set must not contain duplicate quadruplets.

// Example:

// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
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
  vector<vector<int>> fourSum(vector<int>& a, int target) {
    int n = a.size();
    vector<vector<int>> ans;
    if (a.size() == 0) {
      return ans;
    }
    sort(a.begin(), a.end());
    int sm;
    for (int i = 0; i < n - 3;) {
      for (int j = i + 1; j < n - 2;) {
        int fp = j + 1;
        int bp = n - 1;
        while (fp < bp) {
          sm = a[i] + a[j] + a[fp] + a[bp];
          if (sm == target) {
            ans.push_back({a[i], a[j], a[fp], a[bp]});
            fp++;
            while (fp < bp && a[fp] == a[fp - 1]) fp++;
            bp--;
            while (fp < bp && a[bp] == a[bp + 1]) bp--;
          } else if (sm < target) {
            fp++;
          } else {
            bp--;
          }
        }
        j++;
        while (j < n - 2 && a[j] == a[j - 1]) {
          j++;
        }
      }
      i++;
      while (i < n - 3 && a[i] == a[i - 1]) {
        i++;
      }
    }
    return ans;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {{{1, 0, -1, 0, -2, 2}, 0}};
  Solution solution;
  for (auto& i : tc) {
    vector<vector<int>> ans = solution.fourSum(i.first, i.second);
    for (const auto& j : ans) {
      copy(j.begin(), j.end(), ostream_iterator<int>(cout, " "));
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
