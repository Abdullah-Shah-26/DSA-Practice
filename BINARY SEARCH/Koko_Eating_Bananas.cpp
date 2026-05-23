#include <bits/stdc++.h>
using namespace std;

// TC = O(N Log(maxPile))

class Solution {
public:
  bool check(int s, vector<int> &piles, int h){
    int time = 0;

    for(int i = 0; i < piles.size(); i++){
      if(time > h) return false;
    
      // ceil
      time += (piles[i] + s - 1)/s;
    }

    return time <= h;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
  
  int l = 1;
  int r = *max_element(piles.begin(), piles.end());
  int ans = r;

  while(l <= r){
    int mid = l + (r - l)/2;

    if(check(mid, piles, h)){
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