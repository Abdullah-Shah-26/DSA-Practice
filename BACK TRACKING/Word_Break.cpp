class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string>st;
    int n = s.size();
    int maxLen = 0;
    for(auto &word : wordDict){
      maxLen = max(maxLen, (int)word.size());
      st.insert(word);
    }     
    vector<bool>dp(n+1);
    dp[0] = 1;
    // TC = O(N^2)
    // SC = O(N)
    for(int i = 1; i <= n; i++){
      for(int j = i-1; j >= max(0, i - maxLen); j--){
        if(dp[j] && st.count(s.substr(j, i - j))){
          dp[i] = 1;
          break; 
        }
      }
    }
    return dp[n];
    }
};
x