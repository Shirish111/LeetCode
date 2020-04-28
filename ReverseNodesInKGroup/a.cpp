// Reverse Nodes in k-Group

// Given a linked list, reverse the nodes of a linked list k at a time and
// return its modified list.

// k is a positive integer and is less than or equal to the length of the linked
// list. If the number of nodes is not a multiple of k then left-out nodes in
// the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be
// changed.

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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* prehead = new ListNode(-1);
    prehead->next = head;
    int len = length(head);
    if (len <= 1 || k == 1) {
      return head;
    }
    ListNode *cur, *pprev, *prev, *next;
    cur = head;
    pprev = prev = prehead;
    while (len >= k) {
      for (int i = 0; i < k; i++) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }
      next = pprev->next;
      pprev->next = prev;
      pprev = prev = next;
      pprev->next = cur;
      len -= k;
    }
    return prehead->next;
  }
  int length(ListNode* l) {
    int cnt = 0;
    while (l) {
      cnt++;
      l = l->next;
    }
    return cnt;
  }
};
void printList(ListNode* p) {
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
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
void solve() {
  // 1 2 3 4 5 6 7 8, k = 3
  vector<int> v(8);
  iota(v.begin(), v.end(), 1);
  ListNode* head = buildList(v);
  printList(head);
  Solution solution;
  ListNode* l = solution.reverseKGroup(head, 3);
  printList(l);
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
