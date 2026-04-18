#include <bits/stdc++.h>
using namespace std;

//* TC = O(N^2) | SC = O(N^2)

class Solution {
  public:
    int n;

    bool predictTheWinner(vector<int>& a) {
    n = a.size();

    long long sum = 0;10
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

//* We can compress the dimension since we just have 2 players & the game is zero sum - One Gains - Other Loses

class Solution {
  public:
    bool predictTheWinner(vector<int>& a) {
    int n = a.size();

    vector<vector<int>> dp(n, vector<int> (n,0));

    for(int len = 1; len <= n; len++){
      // len = j - i + 1
      // j = len + i - 1
      for(int i = 0; len + i - 1 < n; i++){
        int j = len + i - 1;

        if(len == 1){
          dp[i][j] = a[i];
        }
        else{ 
          int pickL = a[i] - dp[i+1][j];
          int pickR = a[j] - dp[i][j-1];

          dp[i][j] = max(pickL, pickR);
        }
      }
    } 

    return dp[0][n-1] >= 0; 
    }
};

//* Space Optimized

class Solution {
  public:
    bool predictTheWinner(vector<int>& a) {
    int n = a.size();

    vector<int> next(n, 0), cur(n, 0);

    for(int i = n-1; i >= 0; i--){
      cur[i] = a[i]; // i == j, dp[i][j] = a[i]
      for(int j = i + 1; j < n; j++){

        int pickL = a[i] - next[j];
        int pickR = a[j] - cur[j-1];

        cur[j] = max(pickL, pickR);
      }
      next = cur;
    }

    return next[n-1] >= 0; 
    }
};