// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
// Follow up:

// A linked list can be reversed either iteratively or recursively. Could you
// implement both?

// Tags: list, reverse

#include <bits/stdc++.h>
using namespace std;

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
