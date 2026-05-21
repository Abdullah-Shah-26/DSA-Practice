#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
      while(i < j){
        if(s[i] != s[j]){
          return false;
        }
        i++;
        j--;
      }
      return true;
    }

    void solve(int idx, string &s, vector<string> &cur, vector<vector<string>> &ans, vector<vector<bool>> &dp){
      if(idx >= s.size()){
        ans.push_back(cur);
        return;
      }

      for(int i = idx; i < s.size(); i++){
        if(dp[idx][i]){
          cur.push_back(s.substr(idx, i - idx + 1));
          solve(i + 1, s, cur, ans, dp);
          cur.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {
    int n = s.size();

    vector<vector<string>> ans;
    vector<string> cur;
    vector<vector<bool>> dp(n, vector<bool> (n, false));

    for(int i = 0; i < n; i++){
      dp[i][i] = true;
    }

    for(int L = 2; L <= n; L++){
      // len = j - i + 1
      // j = len + i - 1
      for(int i = 0; i < n - L + 1; i++){
        int j = L + i - 1;

        if(s[i] == s[j]){
          if(L == 2){
            dp[i][j] = true;
          }
          else{
            dp[i][j] = dp[i+1][j-1];
          }
        }
      }
    }

    solve(0, s, cur, ans, dp);

    return ans;    
    }
};