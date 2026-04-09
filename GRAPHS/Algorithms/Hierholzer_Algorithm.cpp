#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Valid Arrangement of Pairs - Eulerian Path in Directed Graph
//* TC = O(E) || SC = O(V + E)

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    unordered_map<int, vector<int>> adj;    
    
    // Build In & Out degree
    unordered_map<int,int> inDeg, outDeg; // node, degree

    for(auto &e : pairs){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      inDeg[v]++;
      outDeg[u]++;
    }

    // Find st node of Euler Path
    int stNode = pairs[0][0];
    for(auto &it : adj){
      int node = it.first;
      if(outDeg[node] - inDeg[node] == 1){
        stNode = node; 
        break;
      }
    }

    // Standard DFS
    deque<int> eulerPath;
    stack<int> st;

    st.push(stNode);

    while(!st.empty()){
      int node = st.top();

      if(!adj[node].empty()){
        int nei = adj[node].back();
        adj[node].pop_back();

        st.push(nei);
      }
      else{
        eulerPath.push_front(node);
        st.pop();
      }
    }

    vector<vector<int>> result;

    for(int i = 0; i < eulerPath.size() - 1; i++){
      int st = eulerPath[i];
      int end = eulerPath[i+1];

      result.push_back({st, end});
    }
    return result;
    }
};
