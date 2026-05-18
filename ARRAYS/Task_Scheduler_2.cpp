#include <bits/stdc++.h>
using namespace std;

// Simulation + Tracking prev assigned day using hashmap
// TC = O(N) | SC = O(N)

class Solution {
  public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> lastTime;
    long long day = 0;
    
    for(int &task : tasks){
      if(lastTime.count(task)){
        day = max(day, lastTime[task] + space + 1);
      }
      lastTime[task] = day;
      day++;
    }

    return day;
    }
};