// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively or recursively. Could you
// implement both?

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

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class SolutionR {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head) {
      return head;
    }
    return reverseLinkedList(nullptr, head);
  }
  ListNode *reverseLinkedList(ListNode *prev, ListNode *cur) {
    if (!cur) {
      return prev;
    }
    ListNode *next = cur->next;
    cur->next = prev;
    return reverseLinkedList(cur, next);
  }
};
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *p = head, *q = nullptr, *r;
    while (p) {
      r = p->next;
      p->next = q;
      q = p;
      p = r;
    }
    return q;
  }
};
ListNode *buildList(vector<int> &v) {
  ListNode *head = nullptr, *p;
  for (const auto &i : v) {
    if (head == nullptr) {
      head = new ListNode(i);
      p = head;
    } else {
      p->next = new ListNode(i);
      p = p->next;
    }
  }
  return head;
}
void printList(ListNode *l) {
  ListNode *p = l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
void solve() {
  vector<vector<int>> tc = {{1, 2, 3, 4, 5}};
  Solution s;
  for (auto &i : tc) {
    ListNode *l = buildList(i);
    printList(l);
    l = s.reverseList(l);
    printList(l);
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
