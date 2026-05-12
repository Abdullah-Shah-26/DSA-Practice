#include <bits/stdc++.h>
using namespace std;

// TC = O(n * 2^m)
// SC = O(2^m * n)

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    int m =  req_skills.size();
    int n = people.size();

    unordered_map<string, int> mp;
    for(int i = 0; i < m; i++){
      mp[req_skills[i]] = i;
    }    

    vector<int> pMask(n);
    for(int i = 0; i < n; i++){
      int mask = 0;
      for(string &s : people[i]){
        mask |= (1 << mp[s]);        
      }
      pMask[i] = mask;
    }

    // dp[mask] = vector<int>{} -> best full team achieving this mask
    vector<vector<int>> dp(1 << m, {-1});
    dp[0] = {};

    for(int mask =  0; mask < (1 << m); mask++){
      if(dp[mask] == vector<int>{-1}) continue; // skip unreachable states

      for(int i = 0; i < n; i++){
        int newMask = mask | pMask[i];

        vector<int> temp = dp[mask];
        temp.push_back(i);

        if(dp[newMask] == vector<int>{-1} || temp.size() < dp[newMask].size()){
          dp[newMask] = temp;
        }
      }
    }

    return dp[(1 << m) - 1];
    }
};