// Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be
// changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Tags: list, swapping, miscellaneous

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *p, *q, *r;
    p = head;
    if (p == nullptr) {
      return nullptr;
    }
    q = p->next;
    r = nullptr;
    while (p && q) {
      if (r != nullptr) {
        r->next = q;
      }
      p->next = q->next;
      q->next = p;
      if (head == p) {
        head = q;
      }
      r = p;
      p = p->next;
      if (p) {
        q = p->next;
      } else {
        q = nullptr;
      }
    }
    return head;
  }
};
ListNode* buildList(vector<int>& v) {
  ListNode *head = nullptr, *p;
  for (const auto& i : v) {
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
void printList(ListNode* l) {
  ListNode* p = l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
void solve() {
  vector<int> v1{1};
  ListNode* l = buildList(v1);
  Solution solution;
  l = solution.swapPairs(l);
  printList(l);
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
