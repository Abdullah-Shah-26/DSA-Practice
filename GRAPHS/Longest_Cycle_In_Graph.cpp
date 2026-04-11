#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS + TopoSort
//* TC = O(V + E) | SC = O(V)

class Solution {
public:
    int longestCycle(vector<int>& edges) {
    // BFS - Topo Sort
    int n = edges.size();
    vector<int> Indeg(n,0);

    // Compute Indeg
    for(int i = 0; i < n; i++){
      if(edges[i] != -1){
        Indeg[edges[i]]++;
      }
    }    

    // Push nodes with Indeg = 0 in q
    queue<int>q;
    for(int i = 0; i < n; i++){
      if(Indeg[i]==0){
        q.push(i);
      }
    }

    // Remove All Non Cycle nodes
    while(!q.empty()){
      int u = q.front();
      q.pop();
      int v = edges[u];

      if(v != -1){
        Indeg[v]--;
        if(Indeg[v] == 0){
          q.push(v);
        }
      }
    }

    // Count Cycle Len
    int maxLen = -1;

    vector<bool>vis(n,0);
    for(int i = 0; i < n; i++){
      if(Indeg[i] != 0 && !vis[i]){
        int cnt = 0;
        int cur = i;

        while(!vis[cur]){
          vis[cur] = 1;
          cur = edges[cur];
          cnt++;
        }

        maxLen = max(maxLen,cnt);
      }
    }    

    return maxLen;
    }
};

//! DFS TimeStamp + inPath Tracking
//* TC = O(N) | SC = O(N)

class Solution {
  public:
    int longestCycle(vector<int>& edges) {
    int n = edges.size();
    int maxLen = -1;

    vector<bool> vis(n, 0), inPath(n, 0);
    vector<int> time(n, 0);

    for(int i = 0; i < n; i++){
      if(vis[i]) continue;

      int curNode = i, step = 0;

      while(curNode != -1 && !vis[curNode]){
        vis[curNode] = true;
        inPath[curNode] = true;
        time[curNode] = step++;
        curNode = edges[curNode];
      }

      //* Cycle Check  
      if(curNode != -1 && inPath[curNode]){
        maxLen = max(maxLen, step - time[curNode]);
      }

      // Clean up inPath
      curNode = i;
      while(curNode != -1 && inPath[curNode]){
        inPath[curNode] = false;
        curNode = edges[curNode];
      }
    }

    return maxLen;     
    }
};

//! Array Nesting 

class Solution {
public:
    int arrayNesting(vector<int>& edges) {
    int n = edges.size();
    
    //! Simpler Version of Longest Cycle
    vector<bool>vis(n,0);
    int maxLen = 0;
    for(int i = 0; i < n; i++){
      if(!vis[i]){

        int cur = i;
        int len = 0;

        while(!vis[cur]){
          vis[cur] = 1;
          len++;
          cur = edges[cur];          
        }

      maxLen = max(maxLen, len);
      }
    }
    return maxLen;
    }
};

//! Array Nesting - without visited array

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++){
      if(nums[i] != -1){ // If not visited, Traverse 
        int curNode = i;
        int cnt = 0;

        while(nums[curNode] != -1){
          int next = nums[curNode]; // store edge
          nums[curNode] = -1; // mark as visited
          curNode = next; // move forward

          cnt++;
        }

        maxLen = max(maxLen, cnt);
      }
    } 
   
    return maxLen;    
    }
};