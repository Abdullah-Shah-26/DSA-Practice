#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxTotalReward(vector<int> &rewards) {
    sort(begin(rewards), end(rewards));

    bitset<100000> curReward;
    curReward[0] = 1;

    int p = 0;
    bitset<100000> m;

    for (int num : rewards) {

      while (p < num) {
        m.set(p++);
      }

      bitset<100000> validBits = (curReward & m);
      curReward |= (validBits << num);
    }

    // Find MSB
    int r = curReward.size() - 1;
    while (!curReward[r])
      r--;

    return r;
  }
};