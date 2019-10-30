// Remove Nth Node From End of List

// Given a linked list, remove the n-th node from the end of list and return its
// head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes
// 1->2->3->5. Note:

// Given n will always be valid.

// Follow up:

// Could you do this in one pass?

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
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *h = head, *p, *q = nullptr;
    int k = n;
    while (h) {
      if (k) {
        k--;
        p = head;
      } else {
        q = p;
        p = p->next;
      }
      h = h->next;
    }
    if (q == nullptr) {
      head = head->next;
      delete (p);
    } else {
      q->next = p->next;
      delete (p);
    }
    return head;
  }
};
void printList(ListNode* p) {
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
void solve() {
  ListNode* l = new ListNode(1);
  l->next = new ListNode(2);
  l->next->next = new ListNode(3);
  l->next->next->next = new ListNode(4);
  l->next->next->next->next = new ListNode(5);
  Solution solution;
  l = solution.removeNthFromEnd(l, 2);
  printList(l);
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
