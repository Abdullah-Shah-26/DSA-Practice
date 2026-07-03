#include <bits/stdc++.h>
using namespace std;

// Modified dijkstra

typedef pair<int,int> P;

class Solution {
public:
  int minTime(int n, vector<vector<int>>& edges) {
    vector<vector<tuple<int, int, int>>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      int st = e[2];
      int end = e[3];

      adj[u].push_back({v, st, end});
    } 

    vector<int> times(n, 2e9);
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0});
    times[0] = 0; 

    while(!pq.empty()){
      auto [t, u] = pq.top();
      pq.pop();

      if(t > times[u])
        continue;

      for(auto [v, st, end] : adj[u]){
        int depart = max(t, st); // Since we can wait 

        if(depart <= end){
          int arrive = depart + 1; // Takes +1 more to arrive at v

          if(arrive < times[v]){
            times[v] = arrive;
            pq.push({arrive, v});
          }
        }
      }
    }


    if(times[n - 1] == 2e9)
      return -1;

    return times[n - 1];
  }
};