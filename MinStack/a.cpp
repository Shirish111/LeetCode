// Min Stack

// Design a stack that supports push, pop, top, and retrieving the minimum
// element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

// Example:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

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

class MinStack {
  stack<pair<int, int>> s;

 public:
  /** initialize your data structure here. */
  MinStack() { s.push({INT_MAX, INT_MAX}); }

  void push(int x) { s.push({x, min(x, s.top().second)}); }

  void pop() { s.pop(); }

  int top() { return s.top().first; }

  int getMin() { return s.top().second; }
};

void solve() {
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << "\n";
  // Returns - 3.
  minStack.pop();
  cout << minStack.top() << "\n";
  // Returns 0.
  cout << minStack.getMin() << "\n";
  // Returns - 2.
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
