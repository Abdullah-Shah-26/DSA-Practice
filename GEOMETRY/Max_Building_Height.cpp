#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>>& res) { // restrictions 
   
    // Dummy buildings
    res.push_back({1, 0}); // [id, maxHt]
    res.push_back({n, n-1}); // Best Case - maxHt = n-1
 
    sort(begin(res), end(res));

    int N = res.size();

    // L -> R
    for(int i = 1; i < N; i++){
      int diff = res[i][0] -  res[i - 1][0]; // diff b/w id's
      res[i][1] = min(res[i][1], res[i - 1][1] + diff);
    }
  
    // R -> L
    for(int i = N - 2; i >= 0; i--){
      int diff = res[i + 1][0] - res[i][0];
      res[i][1] = min(res[i][1], res[i + 1][1] + diff); 
    }

    int maxHt = 0;

    for(int i = 1; i < N; i++){
      int leftPos = res[i - 1][0]; // Id1 
      int leftHt = res[i - 1][1]; // h1
      
      int curPos = res[i][0]; // Id2
      int curHt = res[i][1]; // h2

      int htDiff = abs(leftHt - curHt);
      int dist = curPos - leftPos;

      // max(h1, h2) + (Id2 - Id1 - htDiff)/2
      int peak = max(leftHt, curHt) + (dist - htDiff)/2;

      maxHt = max(maxHt, peak); 
    }

    return maxHt;
  }
};