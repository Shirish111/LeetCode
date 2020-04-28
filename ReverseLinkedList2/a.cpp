// Reverse Linked List II

// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:

// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL

// Tags: list, reverse

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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head) {
      return head;
    }
    ListNode *p, *q, *r;
    ListNode* prehead = new ListNode(-1);
    prehead->next = head;
    r = q = prehead;
    p = head;
    for (int i = 1; i < m; i++) {
      r = q = p;
      p = p->next;
    }
    for (int i = m; i <= n; i++) {
      ListNode* tmp = p->next;
      p->next = q;
      q = p;
      p = tmp;
    }
    r->next->next = p;
    r->next = q;
    return prehead->next;
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
  vector<pair<vector<int>, pair<int, int>>> tc = {{{1, 2, 3, 4, 5}, {2, 4}}};
  Solution s;
  for (auto& i : tc) {
    ListNode* l = buildList(i.first);
    printList(l);
    l = s.reverseBetween(l, i.second.first, i.second.second);
    printList(l);
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
