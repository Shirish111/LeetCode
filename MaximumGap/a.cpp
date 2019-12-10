// Maximum Gap

// Given an unsorted array, find the maximum difference between the successive
// elements in its sorted form.

// Return 0 if the array contains less than 2 elements.

// Example 1:

// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
//              (3,6) or (6,9) has the maximum difference 3.
// Example 2:

// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
// Note:

// You may assume all elements in the array are non-negative integers and fit in
// the 32-bit signed integer range. Try to solve it in linear time/space.

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

// Using sorting
class SolutionS {
 public:
  int maximumGap(vector<int>& a) {
    int n = a.size();
    if (n < 2) {
      return 0;
    }
    sort(a.begin(), a.end());
    int mx = 0;
    for (int i = 0; i < n - 1; ++i) {
      mx = max(mx, a[i + 1] - a[i]);
    }
    return mx;
  }
};

// Using Radix Sort
// Using Radix Sort
class SolutionR {
 public:
  int maximumGap(vector<int>& a) {
    int n = a.size();
    if (n < 2) {
      return 0;
    }
    int radix = 10;
    int exp = 1;
    int mx = *max_element(a.begin(), a.end());
    vector<int> b(n);
    while (mx / exp > 0) {
      vector<int> c(radix, 0);
      for (int i = 0; i < n; ++i) {
        c[(a[i] / exp) % 10]++;
      }
      for (int i = 1; i < 10; ++i) {
        c[i] += c[i - 1];
      }
      for (int i = n - 1; i >= 0; --i) {
        b[--c[(a[i] / exp) % 10]] = a[i];
      }
      a = b;
      exp *= 10;
    }
    int maxGap = 0;
    for (int i = 0; i < n - 1; ++i) {
      maxGap = max(maxGap, a[i + 1] - a[i]);
    }
    return maxGap;
  }
};

// Using Pigeon Hole Principle
class Solution {
 public:
  struct Bucket {
    bool used = false;
    int minval = INT_MAX;
    int maxval = INT_MIN;
  };
  int maximumGap(vector<int>& a) {
    int n = a.size();
    if (n < 2) {
      return 0;
    }
    int mini = *min_element(a.begin(), a.end());
    int maxi = *max_element(a.begin(), a.end());
    int bucketSize = max(1, (maxi - mini) / (n - 1));
    int bucketNum = (maxi - mini) / bucketSize + 1;
    vector<Bucket> buckets(bucketNum);
    for (auto& num : a) {
      int bucketIndex = (num - mini) / bucketSize;
      buckets[bucketIndex].used = true;
      buckets[bucketIndex].minval = min(num, buckets[bucketIndex].minval);
      buckets[bucketIndex].maxval = max(num, buckets[bucketIndex].maxval);
    }
    int prevBucketMax = mini, maxGap = 0;
    for (auto& bucket : buckets) {
      if (!bucket.used) {
        continue;
      }
      maxGap = max(maxGap, bucket.minval - prevBucketMax);
      prevBucketMax = bucket.maxval;
    }
    return maxGap;
  }
};
void solve() {
  vector<vector<int>> tc = {
      {3, 6, 9, 1},
      {9, 14, 33, 42},
      {15252, 16764, 27963, 7817,  26155, 20757, 3478,  22602, 20404, 6739,
       16790, 10588, 16521, 6644,  20880, 15632, 27078, 25463, 20124, 15728,
       30042, 16604, 17223, 4388,  23646, 32683, 23688, 12439, 30630, 3895,
       7926,  22101, 32406, 21540, 31799, 3768,  26679, 21799, 23740}};
  Solution s;
  for (auto& i : tc) {
    cout << s.maximumGap(i) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
