#include <bits/stdc++.h>
using namespace std;

 
class Solution {
  public:
  
    // DFS
    bool dfs(vector<int> &arr, int i){
      if(i < 0 || i >= arr.size() || arr[i] < 0) return false;
      if(arr[i] == 0) return true;

      arr[i] *= -1; // Marking as visited
      bool a = dfs(arr, i - arr[i]);
      bool b = dfs(arr, i + arr[i]);

      return a || b;
    }

    bool canReach(vector<int>& arr, int st) {
      // return dfs(arr, st);  

      // BFS
      int n = arr.size();
      vector<bool> vis(n, false);
      queue<int> q;

      q.push(st);
      vis[st] = 1;

      while(!q.empty()){
        int i = q.front();
        q.pop();

        if(arr[i] == 0) return true;

        int left = i - arr[i];
        int right = i + arr[i];

        if(right < n && !vis[right]){
          vis[right] = 1;
          q.push(right);
        }

        if(left >= 0 && !vis[left]){
          vis[left] = 1; 
          q.push(left);
        }
      }

    return false;
    }
};