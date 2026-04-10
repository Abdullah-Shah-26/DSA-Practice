#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Modified Dijkstra
//* TC = O(E Log V) || SC = O(V + E)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int st, int end) {
    vector<pair<int, double>> adj[n];

    for(int i = 0; i < edges.size(); i++){
      int u = edges[i][0];
      int v = edges[i][1];
      double w = succProb[i];

      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }    

    priority_queue<pair<double,int>> pq;
    pq.push({1.0, st});

    vector<double> dist(n, 0.0);
    dist[st] = 1.0;

    while(!pq.empty()){
      auto [dis, node] = pq.top();
      pq.pop();

      // Dijkstra pruning
      if(dis < dist[node]) continue;

      // Reaching node first time with maxProb
      if(node == end) return dist[end];

      for(auto [adjNode, wt]: adj[node]){
        if(dis * wt > dist[adjNode]){
          dist[adjNode] = dis*wt;

          pq.push({dis*wt, adjNode});
        }
      }
    }

    return dist[end];
    }
};