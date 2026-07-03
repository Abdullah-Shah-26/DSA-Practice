#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

class Solution {
public:
  long long minOperations(vector<int>& nums, int x, int k) {
    int n = nums.size();

    // Window Len = x
    // cost[i] = min operations to make nums[i..i+x-1] equal
    // No of windows possible = n - x + 1

    vector<ll> cost(n - x + 1);

    multiset<ll> left, right;
    ll sumL = 0;
    ll sumR = 0;

    auto balance = [&](){
      // Left should have either same size as right
      // or exactly +1 more

      while(left.size() > right.size() + 1){
        auto it = prev(left.end());
        ll val = *it;
        left.erase(it);
        sumL -= val;
        right.insert(val);
        sumR += val;
      }

      while(left.size() < right.size()){
        auto it = right.begin();
        ll val = *it;
        right.erase(it);
        sumR -= val;
        left.insert(val);
        sumL += val;
      } 
    };

    auto add = [&](ll val){
      if(left.empty() || val <= *prev(left.end())){
        left.insert(val);
        sumL += val;
      }
      else{
        right.insert(val);
        sumR += val;
      }
      balance();
    };

    auto remove = [&](ll val){
      auto it = left.find(val);
      
      if(it != left.end()){
        left.erase(it);
        sumL -= val;
      }
      else{
        it = right.find(val);
        right.erase(it);
        sumR -= val;
      }
      balance();
    };

    for(int i = 0; i < n; i++){
      add(nums[i]);

      if(i >= x)
        remove(nums[i - x]);

      if(i >= x-1){
        ll median = *prev(left.end());
        ll costL = median * (ll)left.size() - sumL;
        ll costR = sumR - median * (ll)right.size();
        cost[i - x + 1] = costL + costR;
      }
    }

    /*
    
    # Recursion Version - KnapSack Like

    ll solve(int pos, int taken){
      if(taken == k)
        return 0;

      if(pos > n-x)
        return INF;
      
      ll skip = solve(pos + 1, taken); // Skip

      # Considered current window [x ..... pos + x - 1] which costs cost[pos]
      # Next valid pos starts (pos + x)

      ll take = cost[pos] + solve(pos + x, taken + 1);

      return min(take, skip);
    }
    
    */

    // dp[i][j] = min cost after considering first i elements
    // and choosing j windows

    int m = n - x + 1; // No of valid window starts

    vector<vector<ll>> dp(m + x + 1, vector<ll> (k + 1, INF));

    // If we already choose k windows
    // No more cost is left
    for(int pos = 0; pos <= m + x; pos++)
      dp[pos][k] = 0;

    // Recursion : pos + 1 --->>> pos + x
    // Bottom Up : R ---->>>> L 

    for(int pos = m - 1; pos >= 0; pos--){
      for(int taken = k - 1; taken >= 0; taken--){ // Windows considered
        ll skip = dp[pos + 1][taken]; // Skip this window
        ll take = cost[pos] + dp[pos + x][taken + 1]; // Take this window
        dp[pos][taken] = min(skip, take);
      }
    }

    return dp[0][0];
  }
};