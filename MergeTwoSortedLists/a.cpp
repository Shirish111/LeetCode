// Merge Two Sorted Lists

// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

// Tags: merge, list

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
  int getVal(ListNode* l) { return l == nullptr ? INT_MAX : l->val; }
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p, *head = nullptr;
    int n1, n2, mn;
    while (l1 || l2) {
      n1 = getVal(l1);
      n2 = getVal(l2);
      if (n1 < n2) {
        l1 = l1->next;
        mn = n1;
      } else {
        l2 = l2->next;
        mn = n2;
      }
      if (head == nullptr) {
        head = new ListNode(mn);
        p = head;
      } else {
        p->next = new ListNode(mn);
        p = p->next;
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
  vector<int> v1 = {1, 2, 4};
  vector<int> v2 = {1, 3, 4};
  ListNode* l1 = buildList(v1);
  ListNode* l2 = buildList(v2);
  printList(l1);
  printList(l2);
  Solution solution;
  ListNode* l = solution.mergeTwoLists(l1, l2);
  printList(l);
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
