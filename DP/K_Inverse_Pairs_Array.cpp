#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// * TLE & Wrong Ans on Larger Test Case
class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int n, int k, vector<vector<int>>& dp){
        if(k < 0) return 0;

        if(n == 0)
            return k == 0;   // correct base

        if(dp[n][k] != -1)
            return dp[n][k];

        long long ways = 0;

        for(int inv = 0; inv <= min(n-1, k); inv++){
            ways = (ways + solve(n-1, k-inv, dp)) % MOD;
        }

        return dp[n][k] = ways;
    }

    int countPermWithkInversions(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(n, k, dp);
    }
};
//! Sliding Window DP
class Solution {
public: 
    const int MOD = 1e9 + 7;
  // TC = O(N * K)
  // SC = O(K)
    int kInversePairs(int N, int K) {
        vector<int> prev(K+1,0);
        prev[0] = 1;

        for(int n = 2; n <= N; n++){
            vector<int> cur(K+1,0);
            long long windowSum = 0;

            int maxInv = min(K, n*(n-1)/2);

            for(int k = 0; k <= maxInv; k++){
                windowSum = (windowSum + prev[k]) % MOD;
                if(k >= n) windowSum = (windowSum - prev[k-n] + MOD) % MOD;
                cur[k] = windowSum;
            }

            prev = cur;
        }
        return prev[K];
    }
};