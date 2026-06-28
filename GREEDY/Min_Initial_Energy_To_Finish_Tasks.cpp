#include <bits/stdc++.h>
using namespace std;

// Greedy + BS

class Solution {
public:
  bool can(int mid, vector<vector<int>> &tasks){
    for(auto &t : tasks){
      int actual = t[0];
      int mini = t[1];

      if(mini > mid)
        return false;

      mid -= actual;
    } 

    return true;
  }

  int minimumEffort(vector<vector<int>>& tasks) {
    int l = 0, r = 1e9;
    int ans = 1e9;

    auto cmp = [&](auto t1, auto t2){
      int d1 = t1[1] - t1[0];
      int d2 = t2[1] - t2[0];

      return d1 > d2;
    };

    sort(begin(tasks), end(tasks), cmp);
    
    // why sorting : 
    // Ex : [[2,5], [5,10], [20,100]]
    // mid = 100
    // If we go from back to front, valid
    // Front to back - Invalid 

    while(l <= r){
      int mid = (l + r) >> 1;

      if(can(mid, tasks)){
        ans = mid;
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }    

    return ans;
  }
};