#include <bits/stdc++.h>
using namespace std;

// Brute :

class MyHashSet {
public:
  vector<int> st;

  MyHashSet() { st.resize(1e6 + 1, -1); }

  void add(int key) { st[key] = 1; }

  void remove(int key) { st[key] = -1; }

  bool contains(int key) { return st[key] != -1; }
};

// Optimal :

class MyHashSet {
public:
  int n; // No of buckets
  vector<list<int>> buckets;

  MyHashSet() {
    n = 11000; // Mentioned 10,000 calls
    buckets = vector<list<int>>(n, list<int>{});
  }

  void add(int key) {
    int idx = key % n;

    auto it = find(buckets[idx].begin(), buckets[idx].end(), key);

    if (it == buckets[idx].end())
      buckets[idx].push_back(key);
  }

  void remove(int key) {
    int idx = key % n;

    auto it = find(buckets[idx].begin(), buckets[idx].end(), key);

    if (it != buckets[idx].end())
      buckets[idx].erase(it);
  }

  bool contains(int key) {
    int idx = key % n;

    auto it = find(buckets[idx].begin(), buckets[idx].end(), key);

    if (it != buckets[idx].end())
      return true;

    return false;
  }
};