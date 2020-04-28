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

// Tags: stack

#include <bits/stdc++.h>
using namespace std;

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
