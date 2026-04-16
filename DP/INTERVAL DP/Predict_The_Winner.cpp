#include <bits/stdc++.h>
using namespace std;

//* TC = O(N^2) | SC = O(N^2)

class Solution {
  public:
    int n;

    bool predictTheWinner(vector<int>& a) {
    n = a.size();

    long long sum = 0;
    for(int x : a) sum += x;

    vector<vector<long long>> dp(n, vector<long long> (n,0)); 

    // dp[i][j] = maxScore that i can obtain from this segment

    for(int len = 1; len <= n; len++){
      // len = j - i + 1
      // j = len + i - 1

      for(int i = 0; len + i - 1 < n; i++){
        int j = len + i - 1;

        // BaseCase
        if(len == 1){
          dp[i][j] = a[i];
        }
        else if(len == 2){
          dp[i][j] = max(a[i], a[j]);
        }

        else{
          dp[i][j] = max(a[i] + min(dp[i+2][j], dp[i+1][j-1]), 
                         a[j] + min(dp[i+1][j-1], dp[i][j-2]));
        }
      }
    }

    long long p1 = dp[0][n-1]; // score of player1
    long long p2 = sum - p1; // score of player2

    return p1 >= p2;
    }
};