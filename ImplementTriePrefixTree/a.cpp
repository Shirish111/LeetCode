// Implement Trie (Prefix Tree)

// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.
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

class Trie {
 public:
  struct Node {
    unordered_map<char, Node *> m;
    bool isEnd;
    Node() { isEnd = false; }
  };
  Node *root;
  /** Initialize your data structure here. */
  Trie() { root = new Node(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Node *p = root;
    for (auto &c : word) {
      if (p->m.find(c) == p->m.end()) {
        p->m[c] = new Node();
      }
      p = p->m[c];
    }
    p->isEnd = true;
  }

  Node *_traverse(string &word) {
    Node *p = root;
    for (auto &c : word) {
      if (p->m.find(c) == p->m.end()) {
        return nullptr;
      }
      p = p->m[c];
    }
    return p;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *p = _traverse(word);
    return p != nullptr && p->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) { return _traverse(prefix) != nullptr; }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void solve() {
  Trie *obj = new Trie();
  obj->insert("apple");
  cout << boolalpha << obj->search("apple") << "\n";
  cout << boolalpha << obj->search("app") << "\n";
  cout << boolalpha << obj->startsWith("app") << "\n";
  obj->insert("app");
  cout << boolalpha << obj->search("app") << "\n";
  delete obj;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
