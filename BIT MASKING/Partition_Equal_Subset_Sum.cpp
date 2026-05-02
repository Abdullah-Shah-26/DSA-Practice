#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(),0);

    if(total & 1) return false; 

    int target = total/2;

    // vector<bool> dp(target + 1, 0);
    // dp[0] = 1;

    // for(int num : nums){ // TC = O(N * Target)
    //   for(int s = target; s >= num; s--){
    //     dp[s] = dp[s] | dp[s-num];
    //   }
    // } 

    // return dp[target];


    // TC = O(N * Target / 64)

    bitset<20001> bs;
    bs[0] = 1;

    for(int x : nums) // Add x to every reachable sum
      bs |= (bs << x);

    return bs[target];
    
    }
};