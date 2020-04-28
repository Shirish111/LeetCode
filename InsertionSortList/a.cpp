// Insertion Sort List

// Sort a linked list using insertion sort.

// A graphical example of insertion sort. The partial sorted list (black)
// initially contains only the first element in the list. With each iteration
// one element (red) is removed from the input data and inserted in-place into
// the sorted list

// Algorithm of Insertion Sort:

// Insertion sort iterates, consuming one input element each repetition, and
// growing a sorted output list. At each iteration, insertion sort removes one
// element from the input data, finds the location it belongs within the sorted
// list, and inserts it there. It repeats until no input elements remain.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

// Tags: sorting, list

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
  ListNode* insertionSortList(ListNode* head) {
    if (!head) {
      return head;
    }
    ListNode* prehead = new ListNode(INT_MIN);
    prehead->next = head;
    ListNode *pp, *p, *pr, *r;
    pr = head;
    while (pr->next) {
      r = pr->next;
      pp = prehead;
      p = pp->next;
      while (p != r && p->val <= r->val) {
        pp = p;
        p = p->next;
      }
      if (r == p) {
        pr = r;
        continue;
      }
      pp->next = r;
      pr->next = r->next;
      r->next = p;
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
void printList(ListNode* l) {
  ListNode* p = l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
void solve() {
  vector<vector<int>> tc = {{3, 2, 1}};
  Solution s;
  for (auto& i : tc) {
    ListNode* l = buildList(i);
    cout << "Before:"
         << "\n";
    printList(l);
    l = s.insertionSortList(l);
    cout << "After:"
         << "\n";
    printList(l);
    cout << "Done"
         << "\n\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
