#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumSwap(string s1, string s2) {
    int n = s1.size();
    int xy = 0, yx = 0;

    for (int i = 0; i < n; i++) {
      if (s1[i] == 'x' && s2[i] == 'y')
        xy++;
      else if (s1[i] == 'y' && s2[i] == 'x')
        yx++;
    }

    if (xy % 2 != yx % 2)
      return -1;

    int ans = (xy / 2) + (yx / 2);

    if (xy & 1)
      ans += 2;

    return ans;
  }
};