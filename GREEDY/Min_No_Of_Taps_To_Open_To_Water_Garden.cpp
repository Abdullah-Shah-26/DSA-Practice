#include <bits/stdc++.h>
using namespace std;

// TC = O(N) = SC
// Greedy 

class Solution {
  public:
    int minTaps(int n, vector<int>& ranges) {
    vector<int> stEnd(n + 1);

    for(int i = 0; i < ranges.size(); i++){
      int st = max(0, i - ranges[i]);
      int end = min(n, i + ranges[i]);

      stEnd[st] = max(stEnd[st], end);
    }    

    int taps = 0;
    int maxEnd = 0;
    int curEnd = 0;

    for(int i = 0; i <= n; i++){
      if(i > maxEnd) return -1;

      if(i > curEnd){
        taps++;
        curEnd = maxEnd;
      }

      maxEnd = max(maxEnd, stEnd[i]);
    }

    return taps; 
    }
};

// Rec + Memo

class Solution {
  public:
    int n;
    map<pair<int,int>, int> dp;
    int solve(int i, int maxEnd, vector<vector<int>> &range){
      if(i >= range.size()){
        if(maxEnd >= n) // No Taps Needed Now
          return 0;
        else  // Invalid Case
          return 1e9; 
      }

      if(range[i][0] > maxEnd) // Gaps Left In B/w
        return 1e9;

      if(dp.count({i, maxEnd})) return dp[{i, maxEnd}];

      int dontOpenTap = solve(i + 1, maxEnd, range);  
      int openTap = 1 + solve(i + 1, max(maxEnd, range[i][1]), range);

      return dp[{i, maxEnd}] = min(dontOpenTap, openTap);
    }

    int minTaps(int N, vector<int>& ranges) {
      n = N;
      vector<vector<int>> range;

      for(int i = 0; i < ranges.size(); i++){
        int left = max(0, i - ranges[i]);
        int right = min(n, i + ranges[i]);

        range.push_back({left, right});
      }

      sort(range.begin(), range.end());

      int ans = solve(0, 0, range);

      return ans == 1e9 ? -1 : ans;
    }
};