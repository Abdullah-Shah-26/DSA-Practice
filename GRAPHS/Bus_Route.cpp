#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS
//* TC = O(V + E)  V = n , E = k stops
//* SC = O(V + E)

// Bus as Node, 
class Solution {
  public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int dst) {
    if(src == dst) return 0;
    int n = routes.size();   

    unordered_map<int, vector<int>> adj; // stops, busNo

    for(int i = 0; i < n; i++){
      for(auto &s: routes[i]){
        adj[s].push_back(i); 
      }
    }

    vector<bool> vis(501,0); // buses visited
    queue<int> q;

    for(auto &busNo : adj[src]){
      q.push(busNo);
      vis[busNo] = 1;
    }

    int busCnt = 1; // Got into bus at src stop initally
    while(!q.empty()){
      int size = q.size();

      while(size--){
        int bus = q.front();
        q.pop();

        // How many stops can this bus visit that aren't visited
        for(auto &stop : routes[bus]){
          if(stop == dst){
            return busCnt;
          }

          for(auto &nextBus : adj[stop]){
            if(!vis[nextBus]){
              vis[nextBus] = 1;
              q.push(nextBus);
            }
          }
        }
      }

      busCnt++;
    }

    return -1;
    }
};