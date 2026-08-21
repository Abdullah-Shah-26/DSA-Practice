#include <bits/stdc++.h>
using namespace std;

class Allocator {
  int n;
  vector<int> blocks;

public:
  Allocator(int _n) : n(_n) { blocks.resize(n, 0); }

  int allocate(int size, int mID) {
    for (int i = 0; i < n; i++) {
      if (blocks[i] != 0)
        continue;

      int continousFree = 0;
      int st = i;

      while (i < n && blocks[i] == 0) {
        continousFree++;
        i++;
      }

      if (continousFree >= size) {
        for (int j = st; j < st + size; j++)
          blocks[j] = mID;

        return st;
      }
    }

    return -1;
  }

  int freeMemory(int mID) {
    int freed = 0;

    for (int i = 0; i < n; i++) {
      if (blocks[i] == mID) {
        freed++;
        blocks[i] = 0;
      }
    }

    return freed;
  }
};
