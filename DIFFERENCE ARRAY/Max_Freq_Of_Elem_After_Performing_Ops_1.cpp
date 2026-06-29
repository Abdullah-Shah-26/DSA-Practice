#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
  // TC = O(maxElem)
  // SC = O(maxElem)

    int maxFrequency(vector<int>& nums, int k, int numOperations) { 
    int n = nums.size();
    int maxElem = *max_element(begin(nums), end(nums));
    int maxValue = maxElem + k;
    vector<int>diff(maxValue + 2, 0);
    unordered_map<int,int>freq;

    for(auto i : nums){
      freq[i]++;
    }

    for(int i = 0; i < n; i++){
      int l = max(0, nums[i] - k);
      int r = min(nums[i] + k, maxValue);

      diff[l] += 1;
      diff[r + 1] -=1;
    }    
    
    int res = 1;

    for(int target = 0; target <= maxValue; target++)
    {
      if(target > 0) // Find CumSum
      diff[target] += diff[target - 1]; 
    
      int targetFreq = freq[target];
      int needConversion = diff[target] - targetFreq;
      int canConvert = min(needConversion, numOperations);  
      res = max(res, targetFreq + canConvert);
    }
    return res;
    }
};