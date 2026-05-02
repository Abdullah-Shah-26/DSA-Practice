#include <bits/stdc++.h>
using namespace std;

//! Naive Recursion

class Solution {
  public:
    int n, k;
    int f(int i, int bucketNo, int bucketSum, const int reqSum, vector<int>& nums, int vis){

      if(bucketNo == k) return true; 
      if(bucketSum > reqSum) return false;
      if(bucketSum == reqSum) return f(0, bucketNo + 1, 0, reqSum, nums, vis);
      if(i >= n) return false;

      if(vis & (1 << i)) return f(i + 1, bucketNo, bucketSum, reqSum, nums, vis);
      else{

        // Take
        bool take = f(i + 1, bucketNo, bucketSum + nums[i], reqSum, nums, vis | (1 << i));

        // Skip
        bool skip = f(i + 1, bucketNo, bucketSum, reqSum, nums, vis);

        return take | skip;
      }
    }

    bool canPartitionKSubsets(vector<int>& nums, int K) {
      n = nums.size();    
      k = K;

      sort(nums.rbegin(), nums.rend());

      int sum = accumulate(nums.begin(), nums.end(), 0);

      if(sum % k != 0) return false; // Cannot make k buckets of equal sum

      int reqSum = sum / k; // Required sum of each bucket
  
      return f(0, 0, 0, reqSum, nums, 0);
    }
};

//! Rec + Memo - TC = O(N * 2^N) | SC =  O(2^N)

class Solution {
  public:
    int n,k,target;
    vector<int> nums;
    vector<int> dp; // Memoization
  
    bool dfs(int mask, int curSum){
      if(mask == (1 << n) - 1) return true; // All arr elements must be used

      if(dp[mask] != -1) return dp[mask];
    
      for(int j = 0; j < n; j++){

        if(mask & (1 << j)) continue; // Already Used
        if(curSum + nums[j] > target) continue;

        int nextSum = (curSum + nums[j]) % target; // Resets to 0 automatically if equals target

        if(dfs(mask | (1 << j), nextSum))
          return dp[mask] = true;
      }

      return dp[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& arr, int K) {
    n = arr.size();
    k = K;
    nums = arr;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum % k != 0) return false; 

    target = sum/k; // Req sum of each bucket

    sort(nums.rbegin(), nums.rend()); // Stronger Pruning
    if(nums[0] > target) return false;

    dp.assign(1 << n, -1);
  
    return dfs(0, 0);
    }
};  


// BackTracking : TC = O(k^n) WC , with pruning practially O(n * 2^n)
class Solution {
public:
    bool dfs(int i, vector<int> &nums, vector<int> &bucket, int target){
      if(i == nums.size()) return true;
        
      for(int b = 0; b < bucket.size(); b++){
        if(b > 0 && bucket[b] == bucket[b-1]) continue;

        if(bucket[b] + nums[i] > target) continue;

        bucket[b] += nums[i];
        if(dfs(i+1, nums, bucket, target)) return true;
        bucket[b] -= nums[i];

        if(bucket[b] == 0) break; // prune
      }

      return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % k != 0) return false;
    
    sort(nums.rbegin(), nums.rend()); // Big early faster pruning

    int target = sum/k;

    vector<int> bucket(k,0);

    return dfs(0, nums, bucket, target);    
    }
};