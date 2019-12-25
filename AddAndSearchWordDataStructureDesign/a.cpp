// Add and Search Word - Data structure design

// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string
// containing only letters a-z or .. A . means it can represent any one letter.

// Example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
// Note:
// You may assume that all words are consist of lowercase letters a-z

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

class WordDictionary {
 public:
  struct Node {
    bool isEnd;
    unordered_map<char, Node *> m;
    Node() { isEnd = false; }
  };
  Node *root;
  /** Initialize your data structure here. */
  WordDictionary() { root = new Node(); }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    Node *p = root;
    for (auto &c : word) {
      if (p->m.find(c) == p->m.end()) {
        p->m[c] = new Node();
      }
      p = p->m[c];
    }
    p->isEnd = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return search(word, 0, word.length(), root); }
  bool search(string &word, int beg, int n, Node *p) {
    for (int i = beg; i < n; ++i) {
      if (word[i] != '.') {
        if (p->m.find(word[i]) == p->m.end()) {
          return false;
        }
        p = p->m[word[i]];
      } else {
        for (auto &j : p->m) {
          if (search(word, i + 1, n, p->m[j.first])) {
            return true;
          }
        }
        return false;
      }
    }
    return p->isEnd;
  }
};
void solve() {
  vector<vector<pair<string, string>>> tc = {{{"addWord", "a"},
                                              {"addWord", "a"},
                                              {"search", "."},
                                              {"search", "a"},
                                              {"search", "aa"},
                                              {"search", "a"},
                                              {"search", ".a"},
                                              {"search", "a."}}};
  for (auto &i : tc) {
    WordDictionary *w = new WordDictionary();
    for (auto &j : i) {
      if (j.first == "addWord") {
        w->addWord(j.second);
      } else {
        cout << boolalpha << w->search(j.second) << "\n";
      }
    }
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
