// Implement Stack using Queues

// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Example:

// MyStack stack = new MyStack();

// stack.push(1);
// stack.push(2);
// stack.top();   // returns 2
// stack.pop();   // returns 2
// stack.empty(); // returns false
// Notes:

// You must use only standard operations of a queue -- which means only push to
// back, peek/pop from front, size, and is empty operations are valid. Depending
// on your language, queue may not be supported natively. You may simulate a
// queue by using a list or deque (double-ended queue), as long as you use only
// standard operations of a queue. You may assume that all operations are valid
// (for example, no pop or top operations will be called on an empty stack).

#include <bits/stdc++.h>
using namespace std;

class MyStack {
  queue<int>*q1, *q2;
  int n;
  int top1;

 public:
  /** Initialize your data structure here. */
  MyStack() {
    q1 = new queue<int>();
    q2 = new queue<int>();
    n = 0;
  }

  /** Push element x onto stack. */
  void push(int x) {
    q1->push(x);
    top1 = x;
    ++n;
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    if (!q2->empty()) {
      q2->pop();
    }
    for (int i = 1; i < n; ++i) {
      top1 = q1->front();
      q2->push(top1);
      q1->pop();
    }
    --n;
    int num = q1->front();
    q1->pop();
    swap(q1, q2);
    return num;
  }

  /** Get the top element. */
  int top() { return top1; }

  /** Returns whether the stack is empty. */
  bool empty() { return q1->empty(); }
};

void solve() {
  MyStack stk;
  stk.push(1);
  stk.push(2);
  cout << stk.pop() << "\n";                 // returns 2
  cout << stk.top() << "\n";                 // returns 2
  cout << boolalpha << stk.empty() << "\n";  // returns false
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
