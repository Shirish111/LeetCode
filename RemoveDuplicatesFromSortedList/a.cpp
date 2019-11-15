// Remove Duplicates from Sorted List

// Given a sorted linked list, delete all duplicates such that each element
// appear only once.

// Example 1:

// Input: 1->1->2
// Output: 1->2
// Example 2:

// Input: 1->1->2->3->3
// Output: 1->2->3

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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) {
      return head;
    }
    ListNode *p, *q;
    q = head;
    p = q->next;
    while (p) {
      if (p->val == q->val) {
        q->next = p->next;
        delete p;
        p = q->next;
      } else {
        q = p;
        p = q->next;
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
void printlist(ListNode* l) {
  ListNode* p = l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
void solve() {
  vector<vector<int>> tc = {{1, 1, 2}, {1, 1, 2, 3, 3}};
  Solution s;
  for (auto& i : tc) {
    ListNode* l = buildList(i);
    printlist(l);
    l = s.deleteDuplicates(l);
    printlist(l);
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
