// Word Ladder

// Given two words (beginWord and endWord), and a dictionary's word list, find
// the length of shortest transformation sequence from beginWord to endWord,
// such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not
// a transformed word. Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
// "dog" -> "cog", return its length 5. Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: 0

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
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int ladder = 1;
    unordered_set<string> wordSet;
    for_each(wordList.begin(), wordList.end(),
             [&](string& s) -> void { wordSet.insert(s); });
    wordSet.insert(beginWord);
    queue<string> q;
    q.push(beginWord);
    while (!q.empty()) {
      int cnt = q.size();
      for (int i = 0; i < cnt; i++) {
        string cur = q.front();
        q.pop();
        if (wordSet.find(cur) == wordSet.end()) {
          continue;
        }
        if (cur == endWord) {
          return ladder;
        }
        wordSet.erase(wordSet.find(cur));
        vector<string> adjacent = get_adjacent(cur, wordSet);
        for (auto& word : adjacent) {
          q.push(word);
        }
      }
      ladder++;
    }
    return 0;
  }
  vector<string> get_adjacent(string& cur, unordered_set<string>& wordSet) {
    int n = cur.length();
    vector<string> adjacent;
    for (char i = 'a'; i <= 'z'; i++) {
      for (int j = 0; j < n; j++) {
        if (cur[j] != i) {
          int tmp = cur[j];
          cur[j] = i;
          if (wordSet.find(cur) != wordSet.end()) {
            adjacent.push_back(cur);
          }
          cur[j] = tmp;
        }
      }
    }
    return adjacent;
  }
};
void solve() {
  vector<pair<pair<string, string>, vector<string>>> tc = {
      {{"hit", "cog"}, {"hot", "dot", "dog", "lot", "log", "cog"}},
      {{"hit", "cog"}, {"hot", "dot", "dog", "lot", "log"}},
  };
  Solution s;
  for (auto& i : tc) {
    cout << s.ladderLength(i.first.first, i.first.second, i.second) << "\n";
  }
}
int main() {
  // cin.tie(nullptr);
  // ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
