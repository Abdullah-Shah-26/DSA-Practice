#include <bits/stdc++.h>
using namespace std;

// Greedy Problem  : Needs revisit 

class Solution {
public:
  vector<int> maximumMEX(vector<int>& nums) {
    int n = nums.size();

   // freq[x] = freq of x in remaining suffix
    vector<int> freq(n + 1, 0);

    for(int x : nums)
      if(x <= n)  
        freq[x]++;

    auto getMex = [&](){
      int mex = 0;
      while(mex <= n && freq[mex] > 0)
        mex++;
      return mex;
    };

    vector<int> ans;

    int l = 0; // l = beginning of remaining suffix
    while(l < n){

      // Max mex achievable by any segment starting at l 
      int targetMex = getMex();

      // If mex = 0, then 0 doesn't exist anywhere in suffix
      // Therefore every future segment must also have mex = 0
      // Cut 1 element at a time
      if(targetMex == 0){ 
        ans.push_back(0);

        if(nums[l] <= n)
          freq[nums[l]]--;

        l++;
        continue;
      }

      // seen[x] = Have we seen x in cur segment
      vector<bool> seen(targetMex, false);

      // No of required vals(0 ... targetMex - 1)
      // still missing form cur segment
      int need = targetMex;

      int r = l;

      // Expand until we collect every value from 0 -> targetMex - 1
      while(r < n){
        if(nums[r] <= n)
          freq[nums[r]]--;

        if(nums[r] < targetMex && !seen[nums[r]]){
          seen[nums[r]] = 1;
          need--;
        }

        if(need == 0) // cur segment now has targetMex
          break;

        r++;
      }

      ans.push_back(targetMex);
      l = r + 1; // Next segment starts
    }

    return ans;
  }
};
