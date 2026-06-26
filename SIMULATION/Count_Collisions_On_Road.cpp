#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countCollisions(string directions) {
    int right = 0;
    int stable = 0;
    int ans = 0;      

    for(auto &d : directions){
      if(d == 'R'){
        right++;
        continue;
      }
      if(d == 'S'){ // All the prev cars moving towards right will hit this stable car
        ans += right; 
        stable = 1;
        right = 0;
        continue;
      }
      if(d == 'L'){
        if(right > 0){ // RRR[RL]L First collision gives +2 & remaining r's give +1 
        ans += 2;
        ans += (right - 1);
        right = 0;
        stable = 1;
        }
        else{ // SLL
          if(stable) ans++;
        }
      }
    }

    return ans;
  }
};