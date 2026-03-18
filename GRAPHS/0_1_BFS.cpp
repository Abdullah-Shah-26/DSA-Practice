#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;
const int INF = 1e9 + 10;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

const int N = 1e8;
vector<pair<int,int>> adj[N];
vector<int> level(N, INF);
vector<int> vis(N, 0);
int n, m;

int bfs(){
    deque<int>dq;
    dq.push_back(1);

    level[1] = 0;

    while(!dq.empty()){
      int node = dq.front();
      dq.pop_front();

      for(auto it : adj[node]){
        int adjNode = it.first;
        int edgeWt = it.second;

        if(level[node] + edgeWt < level[adjNode]){
            level[adjNode] = level[node] + edgeWt;

            if(edgeWt == 1){
              dq.push_back(adjNode);
            }
            else {
              dq.push_front(adjNode);
            }
        }
      }
    }
    return level[n] == INF ? - 1 : level[n];
}

int main(){
   fastio();
   cin >> n >> m;
   
   for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;

    if(x == y) continue; // Dont put self loops in graph 

    adj[x].push_back({y, 0});
    // Reverse Edge Pushed by us
    adj[y].push_back({x, 1});
   }

   bfs();
}
//!---------------------------------------------------------
class Solution {
  public:
    // TC = O(E) = O(4 * n * m)
    // SC = O(V) = O(n * m) Since this is a grid  
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int minimumObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    // result[i][j] = min dist from [0][0] to [i][j]

    result[0][0] = 0;

    deque<pair<int,int>>dq;
    dq.push_front({0,0});

    while(!dq.empty()){
      auto it = dq.front();
      dq.pop_front();
      int i = it.first;
      int j = it.second;

      for(auto &dir : directions){
        int x = i + dir[0];
        int y = j + dir[1];

        if(x < 0 || x >= m || y < 0 || y >= n){
          continue;
        }

        int wt = grid[x][y];

        if(result[i][j] + wt < result[x][y]){
          result[x][y] = result[i][j] + wt;


          if(wt == 0){
            dq.push_front({x,y});
          } 
          else{
            dq.push_back({x, y});
          }
        }
      }
    }

    return result[m-1][n-1];    
    }
};