#include <bits/stdc++.h>
using namespace std;

// Greedy - TC = O(N) | SC = O(1)

class Solution {
  public:
    bool canJump(vector<int>& a) {
    int n = a.size();
    int maxReach = 0;

    for(int i = 0; i < n; i++){
      if(i > maxReach) return false;
      maxReach = max(maxReach, i + a[i]);
    }

    return true;
    }
};

// Bottom Up - TC = O(N^2)

class Solution {
  public:
    bool canJump(vector<int>& a) {
    int n = a.size();
    vector<bool> dp(n, false);
    dp[n-1] = true; // Base Case

    for(int i = n-2; i >= 0; i--){
      for(int jump = 1; jump <= a[i]; jump++){
        if(i + jump < n && dp[i + jump]){
          dp[i] = true;
        }
      }
    }

    return dp[0];
    }
};