#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Brute Force
class Solution {
public:
    int n;
    int dfs(int i,int curr,int &target, vector<int>&nums){
      if(i == n){
        return curr == target;
      }
      if(curr == target){
        return (1 << (n-i));
      }

      return dfs(i+1,curr|nums[i],target,nums)+dfs(i+1,curr,target,nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
    int target = 0;
    n = nums.size();
    for(int i = 0; i < n; i++){
      target |= nums[i];
    }  
    return dfs(0,0,target,nums);  
    }
};