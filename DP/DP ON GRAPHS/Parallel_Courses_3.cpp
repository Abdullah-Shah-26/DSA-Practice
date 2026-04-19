#include <bits/stdc++.h>
using namespace std;

//* DP on DAG
// finishTime[u] = maxTime to finish task ending at node u
// Longest Path in DAG

class Solution {
  public:
    int minimumTime(int n, vector<vector<int>>& edges, vector<int>& time) {
    vector<int> adj[n + 1];
    vector<int> inDeg(n + 1,0);
    vector<int> finishTime(n + 1, 0);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      inDeg[v]++;
    }

    int maxTotalTime = 0;
    queue<int> q;

    for(int i = 1; i <= n; i++){
      if(inDeg[i] == 0){
        q.push(i);
        finishTime[i] = time[i-1];
        maxTotalTime = max(maxTotalTime, finishTime[i]);
      }
    }
    
    while(!q.empty()){
      int node = q.front();
      q.pop();

      for(int nei : adj[node]){
      
      // Nei can finish after current finishes
      finishTime[nei] = max(finishTime[nei], finishTime[node] + time[nei - 1]);

      inDeg[nei]--;

      if(inDeg[nei] == 0){
        q.push(nei);
        maxTotalTime = max(maxTotalTime, finishTime[nei]);
        }
      }
    }

    return maxTotalTime;
    }
};