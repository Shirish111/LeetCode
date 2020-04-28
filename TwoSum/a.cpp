// Two Sum Problem (https://leetcode.com/problems/two-sum/)

// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

// Tags: two_pointers, hashing, array

#include <bits/stdc++.h>
using namespace std;

ll n;
ll req_sm;
vector<ll> a;
pair<ll, ll> p;
bool f1() {
  // Bruteforce O(n^2)
  F(i, 0, n) {
    F(j, i + 1, n) {
      if (a[i] + a[j] == req_sm) {
        p = {i, j};
        return true;
      }
    }
  }
  return false;
}
bool f2() {
  // Using sorting O(nlogn) and two pointers method
  sort(A(a));
  ll fp = 0, bp = n - 1, sm;
  while (fp < bp) {
    sm = a[fp] + a[bp];
    if (sm == req_sm) {
      p = {fp, bp};
      return true;
    }
    if (sm < req_sm) {
      fp++;
    } else {
      bp--;
    }
  }
  return false;
}
bool f3() {
  // Using Hashing O(n) and using b = req_sm - a
  unordered_map<ll, ll> m;
  F(i, 0, n) {
    if (m.find(req_sm - a[i]) != m.end()) {
      p = {i, m[req_sm - a[i]]};
      return true;
    }
    m[a[i]] = i;
  }
  return false;
}
void solve() {
  cin >> n;
  a.resize(n);
  F(i, 0, n) cin >> a[i];
  cin >> req_sm;
  bool found = f1();  // f2() or f3()
  if (found) {
    cout << "Sum is present"
         << "\n";
    ;
    cout << p.X << " " << p.Y << "\n";
  } else {
    cout << "Sum is not present"
         << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
