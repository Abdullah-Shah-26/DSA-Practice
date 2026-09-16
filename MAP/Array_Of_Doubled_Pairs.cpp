#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    bool can = true;

    sort(begin(arr), end(arr), [&](int a, int b) { return abs(a) < abs(b); });

    unordered_map<int, int> freq;

    for (int x : arr)
      freq[x]++;

    for (int x : arr) {
      if (freq[x] == 0)
        continue;

      if (freq[2 * x] == 0) {
        can = false;
        break;
      }

      freq[x]--;
      freq[2 * x]--;
    }

    return can;
  }
};