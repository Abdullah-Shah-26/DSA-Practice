#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//! Top Down Approach

int dp[301][5001];
int find(int idx, int target , vector<int> &coins, int n){
    // Base case
    if(target == 0)
    return 1;

    if(target < 0 || idx >= n)
    return 0;

    // if value is already calculated return it 
    if(dp[idx][target] != -1)
    return dp[idx][target];

    // coin use kiya                              // coin use nahi kiya
    return dp[idx][target] = find(idx, target - coins[idx],coins ,n) + find(idx + 1, target, coins, n);
}
    int change(int target, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        return find(0, target, coins, n);
    }
};