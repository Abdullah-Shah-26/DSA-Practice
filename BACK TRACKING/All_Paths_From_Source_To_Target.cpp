#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(No of path * Len of each Path) - (P*L) = (2^n * n)
//* SC = O(Storing all paths) = O(P*L) 

class Solution {
public:
    int n;
    void dfs(int node, vector<int> &path, vector<vector<int>> &ans, vector<vector<int>> &adj){
      if(node == n-1){
        ans.push_back(path);
        return;
      }

      for(auto &nei : adj[node]){
        path.push_back(nei); // Do 
        dfs(nei, path, ans, adj); // Explore
        path.pop_back(); // Undo
      }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
    n = adj.size();
    vector<vector<int>> ans;
    
    vector<int> path;
    path.push_back(0);

    dfs(0, path, ans, adj);

    return ans;   
    }
};