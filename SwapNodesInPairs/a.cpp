// Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes, only nodes itself may be
// changed.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

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
