// Gas Station

// There are N gas stations along a circular route, where the amount of gas at
// station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to
// travel from station i to its next station (i+1). You begin the journey with
// an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit
// once in the clockwise direction, otherwise return -1.

// Note:

// If there exists a solution, it is guaranteed to be unique.
// Both input arrays are non-empty and have the same length.
// Each element in the input arrays is a non-negative integer.
// Example 1:

// Input:
// gas  = [1,2,3,4,5]
// cost = [3,4,5,1,2]

// Output: 3

// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 +
// 4 = 4 Travel to station 4. Your tank = 4 - 1 + 5 = 8 Travel to station 0.
// Your tank = 8 - 2 + 1 = 7 Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to
// station 3. Therefore, return 3 as the starting index. Example 2:

// Input:
// gas  = [2,3,4]
// cost = [3,4,3]

// Output: -1

// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to
// the next station. Let's start at station 2 and fill up with 4 unit of gas.
// Your tank = 0 + 4 = 4 Travel to station 0. Your tank = 4 - 3 + 2 = 3 Travel
// to station 1. Your tank = 3 - 3 + 3 = 3 You cannot travel back to station 2,
// as it requires 4 unit of gas but you only have 3. Therefore, you can't travel
// around the circuit once no matter where you start.

// Tags: miscellaneous, dynamic_programming

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int startNode = 0;
    int sumGas = 0, sumCost = 0, tank = 0;
    int n = gas.size();
    for (int i = 0; i < n; i++) {
      sumGas += gas[i];
      sumCost += cost[i];
      tank += gas[i] - cost[i];
      if (tank < 0) {
        startNode = i + 1;
        tank = 0;
      }
    }
    if (sumGas >= sumCost) {
      return startNode;
    }
    return -1;
  }
};
void solve() {
  vector<pair<vector<int>, vector<int>>> tc = {
      {{1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}}, {{2, 3, 4}, {3, 4, 3}}};
  Solution s;
  for (auto& i : tc) {
    cout << s.canCompleteCircuit(i.first, i.second) << "\n";
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
