// LRU Cache

// Design and implement a data structure for Least Recently Used (LRU) cache. It
// should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key
// exists in the cache, otherwise return -1. put(key, value) - Set or insert the
// value if the key is not already present. When the cache reached its capacity,
// it should invalidate the least recently used item before inserting a new
// item.

// The cache is initialized with a positive capacity.

// Follow up:
// Could you do both operations in O(1) time complexity?

// Example:

// LRUCache cache = new LRUCache( 2 /* capacity */ );

// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4

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

class LRUCache {
  struct Node {
    int key, value;
    Node(int key, int value) : key(key), value(value) {}
  };
  list<Node> l;
  unordered_map<int, list<Node>::iterator> m;
  int size;

 public:
  LRUCache(int capacity) { size = capacity; }

  void put(int key, int value) {
    auto t = m.find(key);
    if (t == m.end()) {
      if (size == 0) {
        m.erase(m.find(l.back().key));
        l.pop_back();
      } else {
        size--;
      }
    } else {
      if (t->second == l.begin()) {
        l.begin()->value = value;
        return;
      }
      l.erase(t->second);
    }
    l.push_front(Node(key, value));
    m[key] = l.begin();
  }
  int get(int key) {
    auto t = m.find(key);
    if (t == m.end()) {
      return -1;
    }
    int value = t->second->value;
    if (t->second != l.begin()) {
      put(key, value);
    }
    return value;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
void solve() {
  LRUCache cache(3);
  cache.put(1, 1);
  cache.put(2, 2);
  cache.put(3, 3);
  cache.put(4, 4);
  cout << cache.get(4) << "\n";  // returns 1
  cout << cache.get(3) << "\n";  // returns 1
  cout << cache.get(2) << "\n";  // returns 1
  cout << cache.get(1) << "\n";  // returns 1
  cache.put(5, 5);
  cout << cache.get(1) << "\n";  // returns 1
  cout << cache.get(2) << "\n";  // returns 1
  cout << cache.get(3) << "\n";  // returns 1
  cout << cache.get(4) << "\n";  // returns 1
  cout << cache.get(5) << "\n";  // returns 1
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
