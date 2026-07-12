#include <bits/stdc++.h>
using namespace std;

// TC = O(N) = SC

class Solution {
  public:
    int n;
    int dfsIt(int root, vector<int> adj[], string &s, int &ans){

      // dp[u] = best downward valid chain starting at u
      vector<int> dp(n, 1);
      stack<pair<int, bool>>st;

      st.push({root, 0});
      
      while(!st.empty()){
        auto [u, state] = st.top();
        st.pop();

        if(state == 1){
          // Its children are already computed now process it
          int max1 = 0, max2 = 0;

          for(int v : adj[u]){
            if(s[u] == s[v]) continue;

            int childLen = dp[v];

            if(childLen > max1){
              max2 = max1;
              max1 = childLen;
            }
            else if(childLen > max2){
              max2 = childLen;
            }
          }

          ans = max(ans, max1 + max2 + 1);
          dp[u] = max1 + 1;
        }
        else{
          st.push({u, 1});

          for(int v: adj[u]){
            st.push({v, 0});
          }
        }
      }
      return ans;
    }

    // dfs(u) = Len of largest downward chain
    int dfs(int u, vector<int> adj[], string &s, int &ans){
      
      int max1 = 0, max2 = 0;
      for(int v : adj[u]){
        int childLen = dfs(v, adj, s, ans);

        if(s[u] == s[v]) continue;

        // Find best, and 2nd best largest chains

        if(childLen > max1){
          max2 = max1;
          max1 = childLen;
        }
        else if(childLen > max2){
          max2 = childLen;
        }
      }

      // c1 ----- node ----- c2
      ans = max(ans, max1 + max2 + 1); // +1 cause cur node contributes to pathLen
      return max1 + 1; // return best childLen upward
    }

    int longestPath(vector<int>& parent, string s) {
    n = parent.size();
    vector<int> adj[n];
    int root = -1;

    for(int i = 0; i < n; i++){
      int p = parent[i];
      if(p == -1){
        root = i; 
        continue;
      }
      adj[p].push_back(i);
    } 
    int ans = 0;
    
    dfsIt(root, adj, s, ans);
    
    return ans;
    }
};