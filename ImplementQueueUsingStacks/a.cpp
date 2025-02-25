// Implement Queue using Stacks

// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.
// Example:

// MyQueue queue = new MyQueue();

// queue.push(1);
// queue.push(2);
// queue.peek();  // returns 1
// queue.pop();   // returns 1
// queue.empty(); // returns false
// Notes:

// You must use only standard operations of a stack -- which means only push to
// top, peek/pop from top, size, and is empty operations are valid. Depending on
// your language, stack may not be supported natively. You may simulate a stack
// by using a list or deque (double-ended queue), as long as you use only
// standard operations of a stack. You may assume that all operations are valid
// (for example, no pop or peek operations will be called on an empty queue).

// Tags: stack, queue

#include <bits/stdc++.h>
using namespace std;

class MyQueue {
  stack<int> s1, s2;

 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    s1.push(x);
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int num = s1.top();
    s1.pop();
    return num;
  }

  /** Get the front element. */
  int peek() { return s1.top(); }

  /** Returns whether the queue is empty. */
  bool empty() { return s1.empty(); }
};

void solve() {
  MyQueue q;
  q.push(1);
  q.push(2);
  q.push(3);
  cout << q.pop();
  q.push(4);
  q.push(5);
  cout << q.pop();
  cout << q.pop();
  cout << q.pop();
  cout << q.pop();
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
