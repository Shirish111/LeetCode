// Word Ladder II

// Given two words (beginWord and endWord), and a dictionary's word list, find
// all shortest transformation sequence(s) from beginWord to endWord, such that:

// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord is not
// a transformed word. Note:

// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
// Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: []

// Explanation: The endWord "cog" is not in wordList, therefore no possible
// transformation.

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
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    unordered_set<string> stringSet;
    for_each(wordList.begin(), wordList.end(),
             [&](string &s) -> void { stringSet.insert(s); });
    stringSet.insert(beginWord);
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> dist;
    vector<vector<string>> ans;
    vector<string> solution;
    bfs(beginWord, endWord, stringSet, dist, graph);
    solution.push_back(beginWord);
    dfs(beginWord, endWord, dist, graph, solution, ans);
    return ans;
  }
  void dfs(string &cur, string &endWord, unordered_map<string, int> &dist,
           unordered_map<string, vector<string>> &g, vector<string> &solution,
           vector<vector<string>> &ans) {
    if (cur == endWord) {
      ans.push_back(solution);
      return;
    }
    int curDist = dist[cur];
    for (auto &word : g[cur]) {
      if (dist[word] == curDist + 1) {
        solution.push_back(word);
        dfs(word, endWord, dist, g, solution, ans);
        solution.pop_back();
      }
    }
  }

  void bfs(string &beginWord, string &endWord, unordered_set<string> &stringSet,
           unordered_map<string, int> &dist,
           unordered_map<string, vector<string>> &g) {
    dist[beginWord] = 0;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty()) {
      int cnt = q.size();
      bool fndEnd = false;
      for (int i = 0; i < cnt; i++) {
        string cur = q.front();
        q.pop();
        int curdist = dist[cur];
        vector<string> neighbours = getNeighbours(cur, stringSet);
        g[cur] = neighbours;
        for (auto &word : neighbours) {
          if (dist.find(word) == dist.end()) {
            dist[word] = curdist + 1;
            if (word != endWord) {
              q.push(word);
            } else {
              fndEnd = true;
            }
          }
        }
        if (fndEnd) {
          break;
        }
      }
    }
  }
  vector<string> getNeighbours(string &cur, unordered_set<string> &stringSet) {
    int n = cur.length();
    vector<string> neighbours;
    for (char i = 'a'; i <= 'z'; i++) {
      for (int j = 0; j < n; j++) {
        if (cur[j] != i) {
          char tmp = cur[j];
          cur[j] = i;
          if (stringSet.find(cur) != stringSet.end()) {
            neighbours.push_back(cur);
          }
          cur[j] = tmp;
        }
      }
    }
    return neighbours;
  }
};
void solve() {
  vector<pair<pair<string, string>, vector<string>>> tc = {
      {{"hit", "cog"}, {"hot", "dot", "dog", "lot", "log", "cog"}}};
  Solution s;
  for (auto &i : tc) {
    vector<vector<string>> ans =
        s.findLadders(i.first.first, i.first.second, i.second);
    for (auto &j : ans) {
      copy(j.begin(), j.end(), ostream_iterator<string>(cout, " "));
      cout << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
