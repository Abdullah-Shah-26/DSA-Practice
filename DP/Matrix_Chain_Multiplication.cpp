#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    // for(int i = 0;i < n;i++)
    // {
    //     dp[i][i] = 0;
    // }
    for(int i = n-1;i >= 1 ;i--)
    {
        for(int j = i+1;j < n;j++)
        {
            long long mini = LLONG_MAX;
            for(int k=i; k < j; k++)
            {
            long long NofOps = (1LL * arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
            mini = min(mini,NofOps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}