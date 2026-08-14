#include <bits/stdc++.h>
using namespace std;

// Brute Force :

class MyHashMap {
public:
  int mp[1000001];

  MyHashMap() { memset(mp, -1, sizeof(mp)); }

  void put(int key, int value) { mp[key] = value; }

  int get(int key) { return mp[key]; }

  void remove(int key) { mp[key] = -1; }
};

// Optimal :

class MyHashMap {
public:
  int n = 10000;
  vector<list<pair<int, int>>> buckets;

  MyHashMap() { buckets.resize(n); }

  void put(int key, int value) {
    int bucketNo = key % n;
    auto &chain = buckets[bucketNo];

    for (auto &it : chain) {
      if (it.first == key) {
        it.second = value;
        return;
      }
    }

    chain.emplace_back(key, value);
  }

  int get(int key) {
    int bucketNo = key % n;
    auto &chain = buckets[bucketNo];

    for (auto &it : chain) {
      if (it.first == key)
        return it.second;
    }

    return -1;
  }

  void remove(int key) {
    int bucketNo = key % n;
    auto &chain = buckets[bucketNo];

    // Need arrow to access pointer
    for (auto it = chain.begin(); it != chain.end(); it++) {
      if (it->first == key) {
        chain.erase(it);
        return;
      }
    }
  }
};
