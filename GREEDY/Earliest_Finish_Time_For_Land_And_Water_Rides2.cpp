#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int earliestFinishTime(vector<int>& landStTime, vector<int>& landDur, vector<int>& waterStTime, vector<int>& waterDur) {
  int n = landStTime.size();
  int m = waterStTime.size();

  int landTime = 1e9, waterTime = 1e9;
  int mini1 = 1e9, mini2 = 1e9;

  // Land First then Water
  for(int i = 0; i < n; i++)
    landTime = min(landTime, landStTime[i] + landDur[i]);

  // Water First then Land
  for(int i = 0; i < m; i++){
    waterTime = min(waterTime, waterStTime[i] + waterDur[i]);
    mini1 = min(mini1, max(waterStTime[i], landTime) + waterDur[i]);
  } 

  for(int i = 0; i < n; i++)
    mini2 = min(mini2, max(waterTime, landStTime[i]) + landDur[i]);

  return min(mini1, mini2);
  }
};