#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN) | SC = O(N)

class Solution {
public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    int n = dist.size();
    vector<int> time(n, 0);

    for (int i = 0; i < n; i++) {
      time[i] = ceil((float)dist[i] / speed[i]);
    }

    sort(time.begin(), time.end());

    int timeCharged = 1;
    int killed = 1;

    for (int i = 1; i < n; i++) {
      if (time[i] - timeCharged <= 0) {
        return killed;
      }
      killed++;
      timeCharged++;
    }

    return killed;
  }
};