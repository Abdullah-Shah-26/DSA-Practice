#include <bits/stdc++.h>
using namespace std;

// BFS + CycleDetection

// CycleLen == 2 -> Can Form Chains 
// CycleLen > 2  -> Only Cycle Matters

// TC = O(N^2) in WC cause of multiple BFS calls
// SC = O(N)

class Solution {
  public:
    int bfs(int start, vector<vector<int>> &adj, vector<bool> &vis){ // To Find Max Chain Len
      queue<pair<int,int>> q; // node, pathLen

      q.push({start, 0});
      int maxDist = 0;

      while(!q.empty()){
        auto [node, dist] = q.front();
        q.pop();

        for(int nei : adj[node]){
          if(!vis[nei]){
            vis[nei] = 1;
            maxDist = max(maxDist, dist + 1);  
            q.push({nei, dist + 1});
          }
        }
      }

      return maxDist;
    }

    int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<vector<int>> adj(n);    
    
    for(int i = 0; i < n; i++){
      int u = i;
      int v = favorite[i];

      // Given : u--->v
      // OurGraph : v--->u , Reversing makes our traversal easier & wont affect cycles

      adj[v].push_back(u);
    }

    int longestCycleEmpCnt = 0;
    int happyCoupleEmpCnt = 0; // Cycle of Len = 2 can contribute how much to our ans

    vector<bool> vis(n, false);

    for(int i = 0; i < n; i++){

      if(!vis[i]){

        // [node, Cnt Of Nodes Seen]
        unordered_map<int,int> m;

        int curNode = i;
        int curNodeCnt = 0;

        while(!vis[curNode]){
          vis[curNode] = true;
          m[curNode] = curNodeCnt;

          int nextNode = favorite[curNode];
          curNodeCnt += 1;

          // If nextNode is already visited - Cycle Detected - Find Len
          if(m.count(nextNode)){
            int cycleLen = curNodeCnt - m[nextNode];

            longestCycleEmpCnt = max(longestCycleEmpCnt, cycleLen);

            if(cycleLen == 2){ // Happy Couple :)
              // curNode <----> nextNode 

              vector<bool> visNodes(n, false);

              visNodes[curNode] = 1;
              visNodes[nextNode] = 1; 

              // Can connect these chains
              happyCoupleEmpCnt += (2 + bfs(curNode, adj, visNodes) + bfs(nextNode, adj, visNodes));
            }
            break; 
          }

          curNode = nextNode;
        }
      }
    }

    return max(longestCycleEmpCnt, happyCoupleEmpCnt);
    }
};

//! TopoSort(Khan's) + DP on DAG
//* TC = O(N) | SC = O(N)

class Solution {
  public:
    int maximumInvitations(vector<int>& fav) {
    int n = fav.size();   

    vector<int> indeg(n, 0);
    for(int i = 0; i < n; i++){
      int u = i;
      int v = fav[i];
      indeg[v]++;
    } 

    queue<int> q;
    for(int i = 0; i < n; i++){
      if(indeg[i] == 0){
        q.push(i);
      }
    }

    vector<int> depth(n, 1); // Chain Len ending at node (including itself)

    while(!q.empty()){
      int u = q.front();
      q.pop();

      int v = fav[u];

      depth[v] = max(depth[v], depth[u] + 1);

      indeg[v]--;

      if(indeg[v] == 0){
        q.push(v);
      }
    }

    int longestCycle = 0;
    int twoCycleInvites = 0; // contribution of happy couples

    for(int i = 0; i < n; i++){
      if(indeg[i] == 0) continue;

      int cycleLen = 0;
      int cur = i;

      while(indeg[cur] != 0){
        indeg[cur] = 0;
        cycleLen++;
        cur = fav[cur];
      }

      if(cycleLen == 2){
        int j = fav[i];
        twoCycleInvites += depth[i] + depth[j];
      }
      else{
        longestCycle = max(longestCycle, cycleLen);
      }
    }

    return max(longestCycle, twoCycleInvites);
    }
};