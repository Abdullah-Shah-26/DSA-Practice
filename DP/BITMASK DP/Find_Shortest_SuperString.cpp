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

//! BitMask DP --------------------------------------------------------------------
//* TC = O(N^2 * 2^N)  |  SC = O(N * 2^N)

class Solution {
public:
  string shortestSuperstring(vector<string>& words) {
      int n = words.size();

      // overlap[i][j] = length of longest suffix of words[i]
      // that matches prefix of words[j]
      vector<vector<int>> overlap(n, vector<int>(n));

      // O(N^2 * L^2)
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
              if (i == j) continue;

              // try largest possible overlap first
              for (int k = min(words[i].size(), words[j].size()); k >= 0; k--) {
                  if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                      overlap[i][j] = k;
                      break;
                  }
              }
          }
      }

      // dp[mask][last] = minimum extra length needed to complete superstring from this state
      vector<vector<int>> dp(1 << n, vector<int>(n, -1));

      // parent[mask][last] = next index chosen
      // used later for reconstruction
      vector<vector<int>> parent(1 << n, vector<int>(n, -1));

      // DFS + memo - O(N^2 * 2^N)
      function<int(int,int)> dfs = [&](int mask, int last) {
          // all words used → no extra cost
          if (mask == (1 << n) - 1) return 0;

          int &res = dp[mask][last];
          if (res != -1) return res;

          res = INT_MAX;

          for (int nxt = 0; nxt < n; nxt++) {
              // skip if already used
              if (mask & (1 << nxt)) continue;

              // only add non-overlapping part
              int add = words[nxt].size() - overlap[last][nxt];

              // recursive cost
              int cost = add + dfs(mask | (1 << nxt), nxt);

              // take best transition
              if (cost < res) {
                  res = cost;
                  parent[mask][last] = nxt;
              }
          }
          return res;
      };

      // choose best starting word
      int start = 0, best = INT_MAX;

      for (int i = 0; i < n; i++) {
          // start cost = full length of first word
          int cost = words[i].size() + dfs(1 << i, i);

          if (cost < best) {
              best = cost;
              start = i;
          }
      }

      // reconstruct optimal order using parent table
      string res = words[start];
      int mask = 1 << start, last = start;

      while (true) {
          int nxt = parent[mask][last];
          if (nxt == -1) break;

          // append only non-overlapping suffix
          res += words[nxt].substr(overlap[last][nxt]);

          mask |= (1 << nxt);
          last = nxt;
      }

      return res;
  }
};