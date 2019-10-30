// Merge k Sorted Lists

// Merge k sorted linked lists and return it as one sorted list. Analyze and
// describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if (k == 0) {
      return nullptr;
    }
    return _mergeKLists(lists, 0, k - 1);
  }
  ListNode* _mergeKLists(vector<ListNode*>& kl, int p, int r) {
    if (p < r) {
      int q = (p + r) / 2;
      ListNode* l1 = _mergeKLists(kl, p, q);
      ListNode* l2 = _mergeKLists(kl, q + 1, r);
      return mergeTwoLists(l1, l2);
    }
    return kl[p];
  }
  int getVal(ListNode* l) { return l == nullptr ? INT_MAX : l->val; }
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p, *head = nullptr;
    int n1, n2, mn;
    while (l1 || l2) {
      n1 = getVal(l1);
      n2 = getVal(l2);
      if (n1 < n2) {
        l1 = l1->next;
        mn = n1;
      } else {
        l2 = l2->next;
        mn = n2;
      }
      if (head == nullptr) {
        head = new ListNode(mn);
        p = head;
      } else {
        p->next = new ListNode(mn);
        p = p->next;
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
  vector<ListNode*> kl;
  vector<int> v1 = {1, 4, 5}, v2 = {1, 3, 4}, v3 = {2, 6};
  kl.push_back(buildList(v1));
  kl.push_back(buildList(v2));
  kl.push_back(buildList(v3));
  printList(kl[0]);
  Solution solution;
  printList(solution.mergeKLists(kl));
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
