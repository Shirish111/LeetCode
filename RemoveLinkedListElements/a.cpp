// Remove Linked List Elements

// Remove all elements from a linked list of integers that have value val.

// Example:

// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

// Tags: list

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    if (!head) {
      return head;
    }
    ListNode *prehead = new ListNode(-1);
    prehead->next = head;
    ListNode *q = prehead, *p = head;
    while (p) {
      if (p->val == val) {
        q->next = p->next;
        delete p;
        p = q->next;
      } else {
        q = p;
        p = p->next;
      }
    }
    p = prehead->next;
    delete prehead;
    return p;
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
  vector<pair<vector<int>, int>> tc = {{{6}, 6}};
  Solution s;
  for (auto &i : tc) {
    ListNode *l = buildList(i.first);
    printList(l);
    l = s.removeElements(l, i.second);
    printList(l);
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
