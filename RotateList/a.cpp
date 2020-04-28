// Rotate List

// Given a linked list, rotate the list to the right by k places, where k is
// non-negative.

// Example 1:

// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
// Example 2:

// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL

// Tags: list, rotate

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) {
      return head;
    }
    ListNode* tail;
    int n = length(head, &tail);
    k = k % n;
    if (k == 0) {
      return head;
    }
    int k1 = n - k;
    ListNode *p = head, *q;
    while (k1--) {
      q = p;
      p = p->next;
    }
    tail->next = head;
    q->next = nullptr;
    return p;
  }
  int length(ListNode* p, ListNode** tail) {
    int cnt = 0;
    while (p) {
      *tail = p;
      p = p->next;
      cnt++;
    }
    return cnt;
  }
};
void solve() {
  vector<pair<vector<int>, int>> tc = {
      {{1, 2, 3, 4, 5}, 2}, {{0, 1, 2}, 4}, {{}, 0}};
  Solution s;
  for (auto& i : tc) {
    ListNode* head = buildList(i.first);
    printList(head);
    head = s.rotateRight(head, i.second);
    printList(head);
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
