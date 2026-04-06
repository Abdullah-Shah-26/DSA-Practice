#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(V + E)LogV  + VLogV  || SC = O(V + E)

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Djkstra algo Modified 
      vector<pair<int, int>>adj[n + 1]; // 1 based indexing
        for(int i = 0; i < m ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            // since its an undirected graph
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1, 1e9);
    vector<int>parent(n+1);
    
    for(int i = 1;i <= n;i++)
    parent[i] = i;
    
    dist[1] = 0;
    pq.push({0,1});
    
    while(!pq.empty())
    {
        int dis = pq.top().first;
        int Node = pq.top().second;
        pq.pop();
        
        if (dis > dist[Node]) continue;
        
        for(auto it : adj[Node])
        {
            int adjNode = it.first;
            int edwt = it.second;
            if(dis + edwt < dist[adjNode])
            {
                dist[adjNode] = dis + edwt;
                pq.push({dist[adjNode],adjNode});
                parent[adjNode] = Node;
            }
        }
    }
    
    // if we didnt reach the last node
    if(dist[n] == 1e9) return {-1};
    vector<int>path;
    int node = n;
    // backtracking shortest path 
    while(parent[node] != node)
    {
        path.push_back(node);
        node = parent[node] ;
    }
    
    path.push_back(node);//src
    reverse(path.begin(), path.end());
    
    vector<int> ans;
    ans.push_back(dist[n]);      // Last distance upto end
    ans.insert(ans.end(), path.begin(), path.end()); 
    return ans;
                                 
    }
};