#include <bits/stdc++.h>
using namespace std;

// TC = O(N Log N) | SC = O(N)

class Solution {
  public:
    int maxTwoEvents(vector<vector<int>>& events) {
    int n = events.size();

    sort(begin(events), end(events));

    // Max profit from idx i till n
    vector<int> suff(n, 0);
    suff[n-1] = events[n-1][2];

    for(int i = n-2; i >= 0; i--)
      suff[i] = max(suff[i+1], events[i][2]);
    
    int best = 0;

    for(int i = 0; i < n; i++){
      auto &e = events[i];

      int end = e[1];
      int profit = e[2];

      best = max(best, profit); // Can take atmost 2, so it can be 1 event too.

      // Find the next st > current end
      int next = upper_bound(events.begin() + i + 1, events.end(), vector<int> {end, INT_MAX, INT_MAX}) - events.begin();

      if(next < n)
        best = max(best, profit + suff[next]); 
    } 

    return best;
    }
};