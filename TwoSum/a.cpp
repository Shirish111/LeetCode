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

ll n;
ll req_sm;
vector<ll> a;
bool f1() {
  // Bruteforce O(n^2)
  F(i, 0, n) {
    F(j, i + 1, n) {
      if (a[i] + a[j] == req_sm) {
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
  unordered_map<ll, bool> m;
  F(i, 0, n) {
    if (m.find(req_sm - a[i]) != m.end()) {
      return true;
    }
    m[a[i]] = true;
  }
  return false;
}
void solve() {
  cin >> n;
  a.resize(n);
  F(i, 0, n) cin >> a[i];
  cin >> req_sm;
  bool found = f1(); // f2() or f3()
  if (found) {
    cout << "Sum is present";
  } else {
    cout << "Sum is not present";
  }
  cout << "\n";
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
