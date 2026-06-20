#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPossible(int n, vector<vector<int>>& edges) {
  vector<int> degree(n + 1);

  map<pair<int,int>, bool> hasEdge;

  for(auto &e : edges){
    int u = e[0];
    int v = e[1];

    degree[u]++;
    degree[v]++;

    hasEdge[{u,v}] = 1;
    hasEdge[{v,u}] = 1;
  }

  vector<int> odd; // All nodes with odd degree
  
  for(int i = 1; i <= n; i++){
    if(degree[i] & 1)
      odd.push_back(i);
  }

  int sz = odd.size();

  if(sz == 0) return true; // No nodes with odd degree
  if(sz > 4) return false; // Since we can only add atmost 2 edges, can't modify nodes > 4

  if(sz == 2){
    int a = odd[0];
    int b = odd[1];

    if(!hasEdge[{a,b}]) // We can connect these 2 nodes among themselves & make their degree even
      return true; 

    // Find a node which does't have an edge with both of them, We can connect both via that node
    for(int i = 1; i <= n; i++){
      if(i == a || i == b) continue;

      if(!hasEdge[{i,a}] && !hasEdge[{i,b}])
        return true;
    }

    return false;
  }

  if(sz == 4){
    int a = odd[0];
    int b = odd[1];
    int c = odd[2];
    int d = odd[3];

    // Try all possible ways to flip parity of the 4 odd nodes
    if(!hasEdge[{a,b}] && !hasEdge[{c,d}]) return true;
    if(!hasEdge[{a,c}] && !hasEdge[{b,d}]) return true;
    if(!hasEdge[{a,d}] && !hasEdge[{b,c}]) return true;
  }

  return false;
  }
};