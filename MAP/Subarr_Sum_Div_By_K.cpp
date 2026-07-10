#include <bits/stdc++.h>
using namespace std;

// Prefix Sum + Hashing + Modulo Arithmetic 
// TC : O(N)
// SC : O(K)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> freq(k);
    freq[0] = 1;
    
    int ans = 0;
    int pref = 0;

    for(int i = 0; i < n; i++){
      pref += nums[i];

      int rem = ((pref % k) + k) % k;
      ans += freq[rem];

      freq[rem]++;
    }     

    return ans;
    }
};