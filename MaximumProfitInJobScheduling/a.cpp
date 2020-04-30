// Maximum Profit in Job Scheduling

// We have n jobs, where every job is scheduled to be done from startTime[i] to
// endTime[i], obtaining a profit of profit[i].

// You're given the startTime , endTime and profit arrays, you need to output
// the maximum profit you can take such that there are no 2 jobs in the subset
// with overlapping time range.

// If you choose a job that ends at time X you will be able to start another job
// that starts at time X.

// Example 1:

// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job.
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
// Example 2:

// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit =
// [20,20,100,70,60] Output: 150 Explanation: The subset chosen is the first,
// fourth and fifth job. Profit obtained 150 = 20 + 70 + 60. Example 3:

// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// Output: 6

// Constraints:

// 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
// 1 <= startTime[i] < endTime[i] <= 10^9
// 1 <= profit[i] <= 10^4

// Tags: dynamic_programming, interview, binary_search
// Difficulty: Hard
// Link:
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    vector<vector<int>> a;
    int n = startTime.size();
    for (int i = 0; i < n; ++i) {
      a.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(a.begin(), a.end());
    map<int, int> dp = {{0, 0}};
    for (auto &job : a) {
      int cur = prev(dp.upper_bound(job[1]))->second + job[2];
      if (cur > dp.rbegin()->second) {
        dp[job[0]] = cur;
      }
    }
    return dp.rbegin()->second;
  }
};

void solve() {
  struct Q {
    vector<int> startTime, endTime, profit;
  };
  vector<Q> tc = {Q{{1, 2, 3, 4, 6}, {3, 5, 10, 6, 9}, {20, 20, 100, 70, 60}}};
  Solution s;
  for (auto &i : tc) {
    cout << s.jobScheduling(i.startTime, i.endTime, i.profit);
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
