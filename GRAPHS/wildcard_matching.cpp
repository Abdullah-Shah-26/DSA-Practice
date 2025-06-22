class Solution {
public:
    bool f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // Base cases
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (j < 0 && i >= 0) {
            // Check if remaining characters in s1 are all '*'
            for (int k = 0; k <= i; k++) {
                if (s1[k] != '*') return false;
            }
            return true;
        }
        
        if (dp[i][j] != -1) return dp[i][j];
        
        // If characters match or s1 has '?'
        if (s1[i] == s2[j] || s1[i] == '?') {
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        }
        
        // If s1 has '*'
        if (s1[i] == '*') {
            return dp[i][j] = f(i-1, j, s1, s2, dp) || f(i, j-1, s1, s2, dp);
        }
        
        // Characters don't match
        return dp[i][j] = false;
    }
    
    bool isMatch(string pattern, string text) {
        int n = pattern.size();
        int m = text.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, pattern, text, dp);
    }
}; 