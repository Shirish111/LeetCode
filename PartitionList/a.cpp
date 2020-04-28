// Partition List

// Given a linked list and a value x, partition it such that all nodes less than
// x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the
// two partitions.

// Example:

// Input: head = 1->4->3->2->5->2, x = 3
// Output: 1->2->2->4->3->5

// Tags: list

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
  ListNode* partition(ListNode* head, int x) {
    if (!head) {
      return head;
    }
    ListNode* prehead = new ListNode(x - 1);
    prehead->next = head;
    ListNode *r = prehead, *q = prehead, *p = head;
    while (p) {
      if (p->val < x) {
        if (r == q) {
          r = q = p;
          p = p->next;
        } else {
          q->next = p->next;
          p->next = r->next;
          r->next = p;
          r = p;
          p = q->next;
        }
      } else {
        q = p;
        p = p->next;
      }
    }
    head = prehead->next;
    delete prehead;
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
void printlist(ListNode* l) {
  ListNode* p = l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
void solve() {
  vector<pair<vector<int>, int>> tc = {{{1, 4, 3, 2, 5, 2}, 3}};
  Solution s;
  for (auto& i : tc) {
    ListNode* l = buildList(i.first);
    printlist(l);
    l = s.partition(l, i.second);
    printlist(l);
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
