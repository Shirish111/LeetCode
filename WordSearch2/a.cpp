// Word Search II

// Given a 2D board and a list of words from the dictionary, find all words in
// the board.

// Each word must be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring. The
// same letter cell may not be used more than once in a word.

// Example:

// Input:
// board = [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// words = ["oath","pea","eat","rain"]

// Output: ["eat","oath"]

// Note:

// All inputs are consist of lowercase letters a-z.
// The values of words are distinct.

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

class Solution {
 public:
  struct Node {
    unordered_map<char, Node *> m;
    string *word;
    Node() { word = nullptr; }
  };
  class Trie {
   public:
    Node *root;
    Trie() { root = new Node(); }
    void add(string &word) {
      Node *p = root;
      for (auto &c : word) {
        if (p->m.find(c) == p->m.end()) {
          p->m[c] = new Node();
        }
        p = p->m[c];
      }
      p->word = new string(word);
    }
  };
  vector<string> findWords(vector<vector<char>> &b, vector<string> &words) {
    Trie t;
    for (auto &i : words) {
      t.add(i);
    }
    vector<string> ans;
    int m = b.size();
    if (m == 0) {
      return ans;
    }
    int n = b[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(b, i, j, m, n, t.root, ans);
      }
    }
    return ans;
  }
  void dfs(vector<vector<char>> &b, int i, int j, int m, int n, Node *p,
           vector<string> &ans) {
    char c = b[i][j];
    if (c == '#' || p->m.find(c) == p->m.end()) {
      return;
    }
    p = p->m[c];
    if (p->word != nullptr) {
      ans.push_back(*p->word);
      p->word = nullptr;  // De-duplication
    }
    b[i][j] = '#';  // Visited
    if (i > 0) {
      dfs(b, i - 1, j, m, n, p, ans);
    }
    if (j > 0) {
      dfs(b, i, j - 1, m, n, p, ans);
    }
    if (i < m - 1) {
      dfs(b, i + 1, j, m, n, p, ans);
    }
    if (j < n - 1) {
      dfs(b, i, j + 1, m, n, p, ans);
    }
    b[i][j] = c;  // Unvisited
  }
};
void solve() {
  vector<pair<vector<vector<char>>, vector<string>>> tc = {
      {{{'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}},
       {"oath", "pea", "eat", "rain"}}};
  for (auto &i : tc) {
    Solution s;
    vector<string> ans = s.findWords(i.first, i.second);
    copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " "));
    cout << "\n";
  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
