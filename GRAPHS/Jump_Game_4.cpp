#include <bits/stdc++.h>
using namespace std;

// BFS Level wise 

class Solution {
  public:
  int minJumps(vector<int>& arr) {
  int n = arr.size();
  
  unordered_map<int, vector<int>> mp; // {value, all idx where it occurs}
  for(int i = 0; i < n; i++){
    mp[arr[i]].push_back(i);
  }

  vector<int> vis(n, false);
  queue<int> q;

  q.push(0);
  vis[0] = true;

  int steps = 0;

  while(!q.empty()){
    int sz = q.size();

    while(sz--){
      int curIdx = q.front();
      q.pop();

      int leftIdx = curIdx - 1;
      int rightIdx = curIdx + 1;

      if(curIdx == n-1)
        return steps;

      if(leftIdx >= 0 && !vis[leftIdx]){
        vis[leftIdx] = true;
        q.push(leftIdx);
      }

      if(rightIdx <= n-1 && !vis[rightIdx]){
        vis[rightIdx] = true;
        q.push(rightIdx);
      }

      for(auto &idx : mp[arr[curIdx]]){
        if(!vis[idx]){
          vis[idx] = true;
          q.push(idx);
        }
      }

      mp.erase(arr[curIdx]); // We have put all the idx of this elem in q so erase it
                             // Else loop reruns everytime & TLE
    }

    steps++;
  }

  return steps;
  }
};