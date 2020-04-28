// Add Two Numbers

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their nodes
// contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Tags: list
// Difficulty: Easy
// Status: Done

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *l = nullptr, *head;
    int carry = 0, sm, n1, n2;
    while (l1 != nullptr || l2 != nullptr) {
      n1 = l1 == nullptr ? 0 : l1->val;
      n2 = l2 == nullptr ? 0 : l2->val;
      sm = n1 + n2 + carry;
      carry = sm / 10;
      if (l == nullptr) {
        l = new ListNode(sm % 10);
        head = l;
      } else {
        l->next = new ListNode(sm % 10);
        l = l->next;
      }
      if (l1) {
        l1 = l1->next;
      }
      if (l2) {
        l2 = l2->next;
      }
    }
    if (carry) {
      l->next = new ListNode(carry);
    }
    return head;
  }
};
ListNode *constructList(string s) {
  reverse(s.begin(), s.end());
  ListNode *l = nullptr, *head;
  for (auto &i : s) {
    if (l == nullptr) {
      l = new ListNode(i - '0');
      head = l;
    } else {
      l->next = new ListNode(i - '0');
      l = l->next;
    }
  }
  return head;
}
void printList(ListNode *p) {
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}
void solve() {
  vector<pair<string, string>> tc = {{"243", "564"}};
  Solution s;
  for (auto &i : tc) {
    ListNode *l1 = constructList(i.first);
    ListNode *l2 = constructList(i.second);
    ListNode *l = s.addTwoNumbers(l1, l2);
    printList(l);
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
