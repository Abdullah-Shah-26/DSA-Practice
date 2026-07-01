#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> adj;
  vector<bool> vis;
  vector<bool> present;

  // Marks genetic value inside subtree
  void dfs(int node, vector<int> &nums){
    if(vis[node]) 
      return;
    
    vis[node] = 1;

    // This genetic value exists
    present[nums[node]] = 1;

    for(int nei : adj[node])
      dfs(nei, nums);
  }

  vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int n = nums.size();
    adj.assign(n, {});
    vector<int> ans(n, 1); // If subtree doesnt contain 1, ans is 1 automatically

    for(int i = 1; i < n; i++)
      adj[parents[i]].push_back(i);

    int st = -1;
    for(int i = 0; i < n; i++){
      if(nums[i] == 1){
        st = i;
        break;
      }
    }

    if(st == -1) // No node has genetic value 1
      return ans;

    int maxi = *max_element(begin(nums), end(nums));

    vis.assign(n, false);
    present.assign(maxi + 2, false);
    
    int mex = 1;
    int cur = st;

    // Moving from node containing 1 -> root
    while(cur != -1){
      dfs(cur, nums);

      while(present[mex])
        mex++;

      ans[cur] = mex;
      cur = parents[cur];
    }

    return ans;
  }
};