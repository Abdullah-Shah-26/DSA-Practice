#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

  int depth(int node){
    int d = 0;
    while(node > 1){
      d++;
      node /= 2; // Moving upwards to parent
    }
    return d;
  }

  int LCA(int u, int v){
    int du = depth(u);
    int dv = depth(v);

    // Ensuring depth v > depth u always 
    if(du > dv){
      swap(u, v);
      swap(du, dv);
    }

    // First make depth of (u,v) equal
    while(dv > du){
      v /= 2;
      dv--;
    }

    // Finding LCA 
    while(u != v){
      u /= 2;
      v /= 2;
    }

    return u;
  }
  
  vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;

    for(auto &q : queries){
      int u = q[0];
      int v = q[1];
      int Lca = LCA(u, v);
      int dist = depth(u) + depth(v) - 2 * depth(Lca);
      ans.push_back(dist + 1); // +1 Since we are adding edge & finding cycleLen
    }

    return ans;    
  }
}; 