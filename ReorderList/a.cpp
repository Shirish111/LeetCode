// Reorder List

// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, only nodes itself may be
// changed.

// Example 1:

// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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

class Solution {
 public:
  void reorderList(ListNode *head) {
    // Find the middle Node in the list
    if (!head || !head->next) {
      return;
    }
    ListNode *fast, *pre_middle;
    pre_middle = head;
    fast = head;
    while (fast->next && fast->next->next) {
      pre_middle = pre_middle->next;
      fast = fast->next->next;
    }
    // Reverse Elements from Middle to End
    ListNode *p = pre_middle->next, *q = nullptr, *r = nullptr;
    while (p) {
      q = p->next;
      p->next = r;
      r = p;
      p = q;
    }
    pre_middle->next = nullptr;

    // Reorder
    ListNode *middle = r;
    p = head;
    while (middle) {
      q = p->next;
      r = middle->next;
      p->next = middle;
      middle->next = q;
      p = q;
      middle = r;
    }
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
  vector<vector<int>> tc = {{1, 2, 3, 4}, {1, 2, 3, 4, 5}};
  Solution s;
  for (auto &i : tc) {
    ListNode *l = buildList(i);
    printList(l);
    s.reorderList(l);
    printList(l);
  }
}
int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
