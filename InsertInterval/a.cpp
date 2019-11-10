// Insert Interval

// Given a set of non-overlapping intervals, insert a new interval into the
// intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their
// start times.

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
// Example 2:

// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
// NOTE: input types have been changed on April 15, 2019. Please reset to
// default code definition to get new method signature.

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
  vector<vector<int>> insert(vector<vector<int>> &a, vector<int> &newInterval) {
    vector<vector<int>> ans;
    int n = a.size();
    int i = 0;
    while (i < n && a[i][0] <= newInterval[0]) {
      ans.push_back(a[i]);
      i++;
    }
    int ai = i - 1;
    if (i == 0) {
      ans.push_back(newInterval);
      ai = 0;
    } else {
      if (ans[ai][1] >= newInterval[0]) {
        ans[ai][1] = max(ans[ai][1], newInterval[1]);
      } else {
        ans.push_back(newInterval);
        ai++;
      }
    }
    for (; i < n; i++) {
      if (ans[ai][1] >= a[i][0]) {
        ans[ai][1] = max(ans[ai][1], a[i][1]);
      } else {
        ans.push_back(a[i]);
        ai++;
      }
    }
    return ans;
  }
};
void solve() {
  vector<pair<vector<vector<int>>, vector<int>>> tc = {
      {{{1, 3}, {6, 9}}, {2, 5}},
      {{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}},
      {{{1, 5}}, {0, 3}}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<int>> ans = s.insert(i.first, i.second);
    for (auto &j : ans) {
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
