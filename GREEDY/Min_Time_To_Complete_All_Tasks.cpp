#include <bits/stdc++.h>
using namespace std;

//! Greedy On Intervals
//* TC = O(N * Range)  | SC = O(Range)

class Solution {
  public:
    const int MAXT = 2000;
    int findMinimumTime(vector<vector<int>>& tasks) {
    // Note : At each particular time point, we can run multiple computers simultaneously

    auto cmp = [&](auto &a, auto &b){
      return a[1] < b[1];
    };

    sort(tasks.begin(), tasks.end(), cmp);    

    vector<bool> used(MAXT + 1, 0); // used[t] = 1 means time t is ON

    int ans = 0;
    for(auto &task : tasks){
      int l = task[0];
      int r = task[1];
      int d = task[2];

      int have = 0;

      // Counting already selected points
      for(int i = l; i <= r; i++)
        have += used[i];
      
      int need = d - have;

      // Turning on time points from r will help future tasks
      for(int t = r; t >= l && need > 0; t--){ 
        if(!used[t]){
          used[t] = 1;
          need--;
          ans++; // Used this much time point
        }
      }
    }

    return ans; 
    }
};