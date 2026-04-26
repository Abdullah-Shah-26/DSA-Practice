#include <bits/stdc++.h>
using namespace std;

//! Binary Search + BackTracking
//* TC = O(Sum) * (k ^ n)

class Solution {
  public:
    int ans;

    // Can I assign jobs with maxLoad <= X per worker
    bool dfs(int i, vector<int> &jobs, vector<int> &w, int x){
      if(i == jobs.size()) return true; 

      for(int j = 0; j < w.size(); j++){

        if(j > 0 && w[j] == w[j-1]) continue; // Prune

        if(w[j] + jobs[i] > x) continue; // Worker cannot get job > maxLoad

        w[j] += jobs[i];
        if(dfs(i + 1, jobs, w, x)) return true; 
        w[j] -= jobs[i]; 

        if(w[j] == 0) break; // Prune
      }
      return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend());

    int low = *max_element(jobs.begin(), jobs.end());
    int high = accumulate(jobs.begin(), jobs.end(), 0); // Worst Case - Assigning all jobs to one guy - Sum of all
    ans = high;

    while(low <= high){
      int mid = (low + high) >> 1;

      vector<int> w(k, 0);

      if(dfs(0, jobs, w, mid)){
        ans = mid;
        high = mid - 1;
      }
      else{
        low = mid + 1;  
      }
    }

    return ans;      
    }
};

//! DP + BS 
//* TC = O(3^N * Log(Sum)) | SC = O(2^N)

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
    int n = jobs.size();
    int N = (1 << n);

    // Subset Sums
    vector<int> sum(N,0);
    for(int m = 1; m < N; m++){
      int last = m & -m;
      int idx = __builtin_ctz(last);
      sum[m] = sum[m^last] + jobs[idx];
    }    

    int low = *max_element(jobs.begin(), jobs.end());
    int high = accumulate(jobs.begin(), jobs.end(), 0);
    int ans = high;

    while(low <= high){
      int x = (low + high) >> 1;

      vector<int> dp(N, 1e9); // Min Workers Needed
      dp[0] = 0;

      for(int m = 1; m < N; m++){
        // Try all submasks - grouped 
        for(int sub = m; sub != 0; sub = (sub-1) & m)
          if(dp[m ^ sub] != 1e9 && sum[sub] <= x)
            dp[m] = min(dp[m], dp[m ^ sub] + 1); 
      }

      if(dp[N-1] <= k){
        ans = x;
        high = x-1; 
      }
      else{
        low = x+1;
      }
    }

    return ans;
    }
};