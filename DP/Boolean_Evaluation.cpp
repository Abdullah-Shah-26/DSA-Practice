#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int evaluateExp(string &s) {
    int n = s.size();
    vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(n+1,vector<ll>(2,0)));
    for(int i = 0; i<n; i++)
    {
        if(s[i] == 'T') // was looking for true
        {
            dp[i][i][1] = 1;
            dp[i][i][0] = 0;
        }
        else // Was looking for false
        {
            dp[i][i][0] = 1;
            dp[i][i][1] = 0;
        }
    }
    bool isTrue = 1;
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i+1;j < n; j++)
        {
             if ((j - i) % 2 == 1) continue; // invalid expression

            for(int idx = i+1; idx <= j-1; idx+=2)
            {
                ll LT = dp[i][idx-1][1];
                ll LF = dp[i][idx-1][0];
                ll RT = dp[idx+1][j][1];
                ll RF = dp[idx+1][j][0];

                if(s[idx] == '&')
                {
                    
                    dp[i][j][1] = (dp[i][j][1] + (LT*RT)%mod)%mod;
                   
                    dp[i][j][0] = (dp[i][j][0] + (LT*RF)%mod + (LF*RT)%mod + (LF*RF)%mod)%mod;
               
                }
                else if(s[idx] == '|')
                {
                    
                        dp[i][j][1] = (dp[i][j][1] + (LF*RT)%mod + (LT*RF)%mod + (LT*RT)%mod)%mod;
                   
                        dp[i][j][0] = (dp[i][j][0] + (LF*RF)%mod)%mod;
                    
                }
                else if(s[idx] == '^')
                {
                        dp[i][j][1] = (dp[i][j][1] + (LT*RF)%mod + (LF*RT)%mod)%mod;
                    
                        dp[i][j][0] = (dp[i][j][0] + (LT*RT)%mod + (LF*RF)%mod)%mod;
                    
                }
            }
            
        }
    }
    return dp[0][n-1][1];
}