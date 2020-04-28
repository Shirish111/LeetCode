// Linked List Cycle II

// Given a linked list, return the node where the cycle begins. If there is no
// cycle, return null.

// To represent a cycle in the given linked list, we use an integer pos which
// represents the position (0-indexed) in the linked list where tail connects
// to. If pos is -1, then there is no cycle in the linked list.

// Note: Do not modify the linked list.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the
// second node.

// Example 2:

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the
// first node.

// Example 3:

// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.

// Follow-up:
// Can you solve it without using extra space?

// Tags: two_pointers, list, floyd_cycle

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
  // Floyd's Cylce Detection Algorithm
  ListNode *detectCycle(ListNode *head) {
    if (!head) {
      return head;
    }
    ListNode *slow, *fast;
    slow = head;
    fast = head->next;
    // If the two pointers meet then there is a cycle
    // The difference between the distance travelled
    // by fast and slow ptrs is a multiple of length
    // of loop
    while (slow != fast) {
      if (!fast || !fast->next) {
        return nullptr;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    // Now reset slow to head and increment both pointers by 1
    // They should meet at the start of the loop since the distance
    // covered by both from the start of the loop is equal since they
    // will meet at the same point
    slow = head;
    fast = fast->next;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
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
ListNode *fetchTail(ListNode *head) {
  ListNode *p = head;
  if (!p) {
    return nullptr;
  }
  while (p->next) {
    p = p->next;
  }
  return p;
}
void printList(ListNode *l) {
  ListNode *p = l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
ListNode *constructCircularList(vector<int> &v, int n) {
  ListNode *l = buildList(v);
  printList(l);
  ListNode *t = fetchTail(l);
  ListNode *p = l;
  while (n--) {
    p = p->next;
  }
  t->next = p;
  return l;
}
void solve() {
  vector<pair<vector<int>, int>> tc = {{{3, 2, 0, -4}, 1}, {{1, 2}, 0}};
  Solution s;
  for (auto &i : tc) {
    ListNode *l = constructCircularList(i.first, i.second);
    ListNode *c = s.detectCycle(l);
    if (c != nullptr) {
      cout << c->val;
    } else {
      cout << "nullptr";
    }
    cout << "\n";
  }
}
int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
