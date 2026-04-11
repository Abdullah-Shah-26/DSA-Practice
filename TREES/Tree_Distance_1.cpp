#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

vector<int> bfs(int st, vector<vector<int>> &adj){
  int n = adj.size();
  vector<int> dist(n, -1);

  queue<int> q;
  q.push(st);
  dist[st] = 0;

  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(auto &nei : adj[node]){
      if(dist[nei] == -1){
        dist[nei] = dist[node] + 1;
        q.push(nei); 
      }
    }
  }

  return dist;
}

pair<int,int> bfsFarthest(int st, vector<vector<int>> &adj){
  int n = adj.size();

  queue<int> q;
  vector<int> dist(n, -1);

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

  return {farthest, dist[farthest]}; // node, distance
}

int main(){
  fastio();

  int n;
  cin >> n;

  vector<vector<int>> adj(n+1);

  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto [farthestNode1, dist] = bfsFarthest(1, adj);
  auto [farthestNode2, diameter] = bfsFarthest(farthestNode1, adj);

  vector<int> dist1 = bfs(farthestNode1, adj);
  vector<int> dist2 = bfs(farthestNode2, adj);

  for(int i = 1; i <= n; i++){
    cout << max(dist1[i], dist2[i]) << " ";
  }
  cout << endl;
}
