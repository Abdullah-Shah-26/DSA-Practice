#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n;
    // Max Suffix of a matching with Prefix of b
    int overlap(string &a, string &b){
      int maxLen = min(a.size(), b.size());

      for(int k = maxLen; k >= 0; k--){
        if(a.substr(a.size() - k, a.size()) == b.substr(0, k)){
          return k;
        }
      }
      return 0;
    }

    void dfs(int mask, int last, string curr, vector<string> &nums, string &best){

      if(mask == (1 << n) - 1){
        if(best.empty() || curr.size() < best.size()){
          best = curr;
        }
        return;
      }

      for(int next = 0; next < n; next++){

        if(mask & (1 << next))
          continue;

        int k = overlap(nums[last], nums[next]);
          
        string add = nums[next].substr(k);

        dfs(mask | (1 << next), next, curr + add, nums, best); 
      }
    }

    string shortestSuperstring(vector<string>& words) {
    n = words.size();   
    
    string best = "";

    for(int i = 0; i < n; i++){
      dfs(1 << i, i, words[i], words, best);
    }

    return best;
    }
};