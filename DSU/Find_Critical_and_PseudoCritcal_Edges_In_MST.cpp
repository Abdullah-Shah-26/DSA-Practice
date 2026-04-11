#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = (m^2 + mLogm) || SC = O(n + m)

class DSU {
  public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return (x == parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

class Solution {
  public:
    int n,m;
    int kruskal(vector<vector<int>> &edges, int skipEdge, int addEdge){
      DSU dsu(n);

      int edgesUsed = 0;
      int sum = 0;

      if(addEdge != -1){ // Force Add This Edge
        dsu.unite(edges[addEdge][0], edges[addEdge][1]);
        sum += edges[addEdge][2];
        edgesUsed++;
      }

      for(int i = 0; i < m; i++){
        
        if(i == skipEdge) 
          continue;

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if(dsu.unite(u,v)){
          sum += wt;
          edgesUsed++;
        }
      }

      //! MST has n nodes & n-1 edges else its inValid
      if(edgesUsed != n-1) return INT_MAX; 

      return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int _n, vector<vector<int>>& edges) {
    n = _n;
    m = edges.size();
    //! u, v, wt, original Idx
    for(int i = 0; i < m; i++){
      edges[i].push_back(i); 
    } 

    auto cmp = [&](vector<int> &a, vector<int> &b){
      return a[2] < b[2];
    };

    sort(begin(edges), end(edges), cmp);
    
    int mstWt = kruskal(edges, -1, -1); // Skip Edge, Add Edge

    vector<int> critical;
    vector<int> pCritical; // pseudo critical

    for(int i = 0; i < m; i++){
      
      if(kruskal(edges, i, -1) > mstWt){ // Skipping ith edge - Cost Inc - Critical
        critical.push_back(edges[i][3]);
      }
      else if(kruskal(edges, -1, i) == mstWt){ // ForceAdd ith edge - Same Cost  - Pseudo  
        pCritical.push_back(edges[i][3]);
      }
    } 
  
    vector<vector<int>> ans;

    ans.push_back(critical);
    ans.push_back(pCritical);

    return ans;
    }
};