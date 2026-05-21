#include <bits/stdc++.h>
using namespace std;

// Rec + Memo

class Solution {
  public:
  
  vector<vector<bool>> isPali;
  int dp[2001][2001];

  bool f(int i, string &s, int cnt){
    if(i == s.size() && cnt == 3) return true;
    if(cnt > 3) return false;
    if(dp[i][cnt] != -1) return dp[i][cnt];

    for(int j = i; j < s.size(); j++){
      if(isPali[i][j] && f(j + 1, s, cnt + 1)){
        return true;
      }
    }

    return dp[i][cnt] = false;
  }

    bool checkPartitioning(string s) {
      int n = s.size();
      isPali.assign(n, vector<bool> (n, false));

      for(int i = 0; i < n; i++){
        isPali[i][i] = true;
      }

      for(int L = 2; L <= n; L++){
        for(int i = 0; i < n - L + 1; i++){
          // L = j - i + 1
          int j = L + i - 1;

          if(s[i] == s[j]){
            if(L == 2){
              isPali[i][j] = true;
            }
            else{
              isPali[i][j] = isPali[i+1][j-1];
            }
          }
        }
      }

      memset(dp, -1, sizeof(dp));
      return f(0, s, 0);
    }
};
