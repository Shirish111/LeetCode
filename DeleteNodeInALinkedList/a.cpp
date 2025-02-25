// Delete Node in a Linked List

// Write a function to delete a node (except the tail) in a singly linked list,
// given only access to that node.

// Given linked list -- head = [4,5,1,9], which looks like following:

// Example 1:

// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list
// should become 4 -> 1 -> 9 after calling your function. Example 2:

// Input: head = [4,5,1,9], node = 1
// Output: [4,5,9]
// Explanation: You are given the third node with value 1, the linked list
// should become 4 -> 5 -> 9 after calling your function.

// Note:

// The linked list will have at least two elements.
// All of the nodes' values will be unique.
// The given node will not be the tail and it will always be a valid node of the
// linked list. Do not return anything from your function.

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
  void deleteNode(ListNode* node) {
    ListNode* tmp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete tmp;
  }
};
ListNode* constructList(vector<int>& a) {
  if (a.size() == 0) {
    return nullptr;
  }
  ListNode *h, *l;
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
ListNode* findNode(ListNode* l, int n) {
  ListNode* p = l;
  while (p && n--) {
    p = p->next;
  }
  return p;
}
void printList(ListNode* l) {
  while (l) {
    cout << l->val << " ";
    l = l->next;
  }
  cout << "\n";
}
void solve() {
  vector<pair<vector<int>, int>> tc = {{{4, 5, 1, 9}, 1}};
  Solution s;
  for (auto& i : tc) {
    ListNode* l = constructList(i.first);
    ListNode* node = findNode(l, i.second);
    printList(l);
    s.deleteNode(node);
    printList(l);
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
