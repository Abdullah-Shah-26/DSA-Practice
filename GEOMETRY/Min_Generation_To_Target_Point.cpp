#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minGenerations(vector<vector<int>>& P, vector<int>& t) {
  int vis[7][7][7]{}; // max combination 7 * 7 * 7 = 343 unique points

  vector<array<int,3>> points;
  for(auto vec : P){
    int x = vec[0], y = vec[1], z = vec[2];

    if(!vis[x][y][z]){
      vis[x][y][z] = 1;
      points.push_back({x, y, z});
    }
  }

  if(vis[t[0]][t[1]][t[2]])  
    return 0;

  int cnt = 0; // Count of generation
  while(true){

    vector<array<int,3>> nextGen;
    int m = points.size(); // CurGen
    cnt++;

    for(int i = 0; i < m; i++){
      int x1 = points[i][0];
      int y1 = points[i][1];
      int z1 = points[i][2];

      for(int j = 0; j < m; j++){
        int x2 = points[j][0];
        int y2 = points[j][1];
        int z2 = points[j][2];
      
        int nx = (x1 + x2)/2;
        int ny = (y1 + y2)/2;
        int nz = (z1 + z2)/2;

        if(!vis[nx][ny][nz]){
          vis[nx][ny][nz] = 1;
          nextGen.push_back({nx, ny, nz});

          if(nx == t[0] && ny == t[1] && nz == t[2])
            return cnt;
        }
      }
    }
    if(nextGen.size() == 0) 
        return -1;

    for(auto p : nextGen) // We can from new points using points of all pastGen's
      points.push_back(p); 
  }

  }
};