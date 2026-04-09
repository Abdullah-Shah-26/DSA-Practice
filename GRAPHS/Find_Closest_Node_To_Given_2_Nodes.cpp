#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }


//* TC = O(N) || SC = O(N)
//* Its a Functional Graph - So the first visit is optimal, that's why dist[i] == INT_MAX ? means not visited
//* In general graph [Multiple Paths Possible] we would use Dijkstra & (dist[node] + 1 < dist[nei]) update nei distance 

class Solution {
  public:
    int n;

    //! DFS - Recursive
    void dfs(vector<int> &edges, int node, vector<int> &dist){
      int nei = edges[node];

      if(nei != -1 && dist[nei] == INT_MAX){
        dist[nei] = 1 + dist[node];
        dfs(edges, nei, dist);
      }
    }

    //! DFS - Iterative
    void dfsIt(vector<int> &edges, int node, vector<int> &dist){
      while(node != -1){
        int nei = edges[node];

        if(nei != -1 && dist[nei] == INT_MAX){
          dist[nei] = dist[node] + 1;
          node = nei;
        }
        else
          break;
      }
    }

    //! BFS
    void bfs(vector<int> &edges, int st, vector<int> &dist){
      queue<int> q;

      dist[st] = 0;
      q.push(st);

      while(!q.empty()){
        int node = q.front();
        q.pop();

        int nei = edges[node];

        if(nei != -1 && dist[nei] == INT_MAX){
          dist[nei] = dist[node] + 1;
          q.push(nei);
        }
      }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    n = edges.size();

    vector<int> dist1(n, INT_MAX);
    vector<int> dist2(n, INT_MAX);

    dist1[node1] = 0;
    dist2[node2] = 0;

    dfs(edges, node1, dist1);
    dfs(edges, node2, dist2);

    int minDistNode = -1;
    int minDist = INT_MAX;

    for(int i = 0; i < n; i++){
      int maxi = max(dist1[i], dist2[i]);

      if(maxi < minDist){
        minDist = maxi;
        minDistNode = i;
      }
    }

    return minDistNode;
    }
};