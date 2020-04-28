// Palindrome Linked List

// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true
// Follow up:
// Could you do it in O(n) time and O(1) space?

// Tags: palindrome, list

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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }
    ListNode *pm, *f;
    pm = head;
    f = head->next;
    while (f && f->next) {
      pm = pm->next;
      f = f->next->next;
    }
    pm->next = reverseList(pm->next);
    f = pm->next;
    while (f) {
      if (f->val != head->val) {
        return false;
      }
      head = head->next;
      f = f->next;
    }
    return true;
  }
  ListNode* reverseList(ListNode* l) {
    if (l == nullptr) {
      return l;
    }
    ListNode *p, *q, *r;
    r = q = nullptr;
    p = l;
    while (p) {
      r = p->next;
      p->next = q;
      q = p;
      p = r;
    }
    return q;
  }
};
ListNode* constructList(vector<int>& a) {
  ListNode *l, *h;
  l = h = nullptr;
  for (auto& i : a) {
    if (l == nullptr) {
      h = new ListNode(i);
      l = h;
    } else {
      l->next = new ListNode(i);
      l = l->next;
    }
  }
  return h;
}
void printList(ListNode* l) {
  while (l) {
    cout << l->val << " ";
    l = l->next;
  }
  cout << "\n";
}
void solve() {
  vector<vector<int>> tc = {{1, 2}, {1, 2, 2, 1}};
  Solution s;
  for (auto& i : tc) {
    ListNode* l = constructList(i);
    cout << boolalpha << s.isPalindrome(l) << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
