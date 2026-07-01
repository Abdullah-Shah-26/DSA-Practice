#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)
/*
1) Peel no-coin leaves.
2) Peel leaves once.
3) Peel leaves again.
4) Count surviving edges.
5) Return 2 * surviving_edges.

*/

class Solution {
public:
  int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
  int n = coins.size();

  vector<int> adj[n];
  vector<int> deg(n,0);

  for(auto &e : edges){
    int u = e[0];
    int v = e[1];

    deg[u]++;
    deg[v]++;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }   

  // Remove leaves with no coins 
  queue<int> q;
  for(int i = 0; i < n; i++)
    if(deg[i] == 1 && coins[i] == 0)
      q.push(i);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    deg[u] = 0; // deleted

    for(int v : adj[u]){
      if(deg[v] == 0) continue;

      deg[v]--;

      if(deg[v] == 1 && coins[v] == 0)
        q.push(v);
    }
  }

  // Remove all leaves, coin or no coin does't matter here
  for(int i = 0; i < n; i++)
    if(deg[i] == 1)
      q.push(i);

  int sz = q.size();
  while(sz--){ // 1 BFS Layer 
    int u = q.front();
    q.pop();

    deg[u] = 0;

    for(int v : adj[u]){
      if(deg[v] == 0) 
        continue;
      deg[v]--;
    }
  }

  // Remove all leaves again
  for(int i = 0; i < n; i++)  
    if(deg[i] == 1)
      q.push(i);

  sz = q.size();
  while(sz--){
    int u = q.front();
    q.pop();

    deg[u] = 0;

    for(int v : adj[u]){
      if(deg[v] == 0) 
        continue;
      deg[v]--;
    }
  }

  // Count remaining edges
  int edgesLeft = 0;
  for(int i = 0; i < n; i++){
    edgesLeft += deg[i];
  }

  // Every edge contributes to degree of both endpts 
  edgesLeft /= 2;

  // The remaining edges need to be traversed & need to return back to same start Node
  return edgesLeft * 2;
  }
};