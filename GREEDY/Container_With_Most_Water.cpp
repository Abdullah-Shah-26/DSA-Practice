#include <bits/stdc++.h>
using namespace std;

//* TC = O(N) | SC = O(1)

class Solution {
  public:
    int maxArea(vector<int>& height) {
    int n = height.size();
    int maxWater = 0;
    int l = 0, r = n-1;

    // We need 2 different lines to contain water so l < r 
    // r - l cause here water = gaps in b/w r & l
    // Move boundary thats limiting maxWater 

    while(l < r){
      int h = min(height[l], height[r]);
      int w = r - l;
      maxWater = max(maxWater, h*w);

      if(height[l] < height[r]){
        l++;
      }
      else{   
        r--;
      }

    }

    return maxWater;
    }
};