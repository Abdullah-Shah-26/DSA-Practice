#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubstrings(string word) {
    int n = word.size();
    int cnt = 0;

    vector<int> pos(26, -1);

    for (int i = 0; i < n; i++) {
      int idx = word[i] - 'a';

      if (pos[idx] != -1 && i - pos[idx] + 1 >= 4) {
        cnt++;

        // Reset pos, since we want non intersecting substrings
        // The past substring info is no longer useful
        for (int i = 0; i < 26; i++)
          pos[i] = -1;
      } 
      else if (pos[idx] == -1)
        pos[idx] = i;
    }

    return cnt;
  }
};