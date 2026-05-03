#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // 1. Pure Recursion
    int fibRec(int n) {
        if (n <= 1) return n;
        return fibRec(n - 1) + fibRec(n - 2);
    }

    // 2. Top Down DP (Memoization)
    int solveMemo(int n, vector<int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];

        return dp[n] = solveMemo(n - 1, dp) + solveMemo(n - 2, dp);
    }

    int fibMemo(int n) {
        vector<int> dp(n + 1, -1);
        return solveMemo(n, dp);
    }

    // 3. Bottom Up DP
    int fibTab(int n) {
        if (n <= 1) return n;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    // 4. Space Optimized Bottom Up
    int fibOpt(int n) {
        if (n <= 1) return n;

        int prev2 = 0, prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};