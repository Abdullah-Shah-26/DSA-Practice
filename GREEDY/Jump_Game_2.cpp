#include <bits/stdc++.h>
using namespace std;

// TC = O(N)
// BFS 

class Solution {
  public:
    int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, l = 0, r = 0; 

    while(r < n-1){
      int farthest = 0; // Farthest I can reach from this BFS - Level
      
      for(int i = l; i <= r; i++){
        farthest = max(farthest, i + nums[i]);
      }

      jumps++;
      l = r + 1; // Getting ready for next BFS - Level
      r = farthest; 
    }

    return jumps;
    }
};