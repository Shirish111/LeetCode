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

ll a, b;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class List {
 public:
  ListNode *head, *tail;
  List() { head = tail = nullptr; }
  void addNode(int data) {
    if (!head) {
      head = tail = new ListNode(data);
    } else {
      ListNode *p = new ListNode(data);
      tail->next = p;
      tail = p;
    }
  }
};
List l1, l2;
void initList(List &l, ll n) {
  if (n == 0) {
    l.addNode(0);
  }
  while (n) {
    l.addNode(n % 10);
    n = n / 10;
  }
}
void initialize() {
  initList(l1, a);
  initList(l2, b);
}
ListNode *add(ListNode *l1, ListNode *l2) {
  // O(n) where n is the length of the list
  ListNode *head, *q = nullptr, *p;
  while (l1 || l2) {
    int n1 = l1 == nullptr ? 0 : l1->val;
    int n2 = l2 == nullptr ? 0 : l2->val;
    if (head == nullptr) {
      head = new ListNode(n1 + n2);
    } else {
      p = new ListNode(n1 + n2);
      q->next = p;
    }
    if (l1) {
      l1 = l1->next;
    }
    if (l2) {
      l2 = l2->next;
    }
    q = p;
  }
  return head;
}
void printlist(ListNode *l) {
  ListNode *p = l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "\n";
}
void solve() {
  cin >> a >> b;
  initialize();
  ListNode *l3 = add(l1.head, l2.head);
  printlist(l3);
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}