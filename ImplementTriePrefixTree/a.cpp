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

// Tags: tries, string_manipulation

#include <bits/stdc++.h>
using namespace std;

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
