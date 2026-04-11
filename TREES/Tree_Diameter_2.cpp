#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Using BFS

pair<int,int> bfs(int st, vector<vector<int>> &adj){
  int n = adj.size();
  vector<int> dist(n, -1); // -1 means not visisted 

  queue<int> q;
  q.push(st);
  dist[st] = 0;

  int farthest = st;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(auto &nei : adj[node]){
      
      if(dist[nei] == -1){ 
        dist[nei] = dist[node] + 1;
        q.push(nei);

        if(dist[nei] > dist[farthest]){
          farthest = nei;
        }
      }
    }
  }

  return {farthest, dist[farthest]}; // Farthest Node, Farthest Distance
}

int main(){
  fastio();

  int n;
  cin >> n;

  vector<vector<int>> adj(n + 1);

  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto [farthestNode1, dist] = bfs(1, adj);
  auto [farthestNode2, diameter] = bfs(farthestNode1, adj);

  cout << diameter << endl;

}