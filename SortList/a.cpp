// Sort List

// Sort a linked list in O(n log n) time using constant space complexity.

// Example 1:

// Input: 4->2->1->3
// Output: 1->2->3->4
// Example 2:

// Input: -1->5->3->4->0
// Output: -1->0->3->4->5

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
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    // Cut List into two halves
    ListNode *prev, *slow, *fast;
    slow = fast = head;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;

    // Sort two lists
    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);

    // Merge two lists
    return merge(left, right);
  }
  ListNode *merge(ListNode *left, ListNode *right) {
    ListNode *prehead, *p;
    prehead = p = new ListNode(INT_MIN);
    while (left || right) {
      if (left && right) {
        if (left->val <= right->val) {
          p->next = left;
          left = left->next;
        } else {
          p->next = right;
          right = right->next;
        }
      } else if (left) {
        p->next = left;
        left = left->next;
      } else {
        p->next = right;
        right = right->next;
      }
      p = p->next;
    }
    p->next = nullptr;
    p = prehead->next;
    delete prehead;
    return p;
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
  vector<vector<int>> tc = {{4, 2, 1, 3}, {-1, 5, 3, 4, 0}};
  Solution s;
  for (auto &i : tc) {
    ListNode *l = buildList(i);
    cout << "Before:"
         << "\n";
    printList(l);
    l = s.sortList(l);
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
