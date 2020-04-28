// Count Negative Numbers in a Sorted Matrix

// Given a m * n matrix grid which is sorted in non-increasing order both
// row-wise and column-wise.

// Return the number of negative numbers in grid.

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0
// Example 3:

// Input: grid = [[1,-1],[-1,-1]]
// Output: 3
// Example 4:

// Input: grid = [[-1]]
// Output: 1

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100
// Tags: binary_search
// Difficulty: Easy
// Status: Done

#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void maxch(T &x, T y) {
  x = x > y ? x : y;
}

template <typename T>
inline void minch(T &x, T y) {
  x = x < y ? x : y;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto &i : v) {
    os << i << " ";
  }
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, unordered_map<T, U> &m) {
  for (auto &i : m) {
    os << i.first << " " << i.second << " ";
  }
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &m) {
  for (auto &i : m) {
    os << i.first << " " << i.second << " ";
  }
  return os;
}

//--------------------------

class Solution {
 public:
  int lbinsearch(vector<int> &a, int n, int key) {
    int l = 0, h = n - 1, mid;
    while (l <= h) {
      mid = (l + h) / 2;
      if (a[mid] > key) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
    return l;
  }

  int countNegatives(vector<vector<int>> &grid) {
    int n = grid.size(), idx;
    if (n == 0) {
      return 0;
    }
    int m = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      idx = lbinsearch(grid[i], m, -1);
      cnt += m - idx;
    }
    return cnt;
  }
};

// This solution uses the fact that the negative regions of the matrix will form
// a "staircase" shape, e.g.:
// What this solution then does is to "trace" the outline of the staircase.
// Start from bottom-left corner of the matrix, count in the negative numbers in
// each row.
// ++++++
// ++++--
// ++++--
// +++---
// +-----
// +-----
class Solution2 {
 public:
  int lbinsearch(vector<int> &a, int n, int key) {
    int l = 0, h = n - 1, mid;
    while (l <= h) {
      mid = (l + h) / 2;
      if (a[mid] > key) {
        l = mid + 1;
      } else {
        h = mid - 1;
      }
    }
    return l;
  }

  int countNegatives(vector<vector<int>> &grid) {
    int n = grid.size(), idx;
    if (n == 0) {
      return 0;
    }
    int m = grid[0].size();
    int r = n - 2, col = lbinsearch(grid[0], m, -1);
    int cnt = n - col;
    while (r >= 0 && col < n) {
      if (grid[r][col] >= 0) {
        --col;
      } else {
        cnt += n - col;
        --r;
      }
    }
    return cnt;
  }
};

void solve() {
  vector<vector<vector<int>>> tc = {
      {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}},
      {{3, 2}, {1, 0}},
      {{1, -1}, {-1, -1}},
      {{-1}},
      {{5, 1, 0}, {-5, -5, -5}}};
  Solution s;
  for (auto &i : tc) {
    cout << s.countNegatives(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
