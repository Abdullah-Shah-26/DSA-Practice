#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(1)

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int n = gas.size();
  
  int totalGas = 0;
  int totalCost = 0;

  for(int i = 0; i < n; i++){
    totalGas += gas[i];
    totalCost += cost[i];
  }

  if(totalCost > totalGas) return -1;

  int stIdx = 0;
  int curGas = 0;

  for(int i = 0; i < n; i++){
    curGas += gas[i] - cost[i];

    if(curGas < 0){
      stIdx = i + 1;
      curGas = 0;
    }
  }

  return stIdx;
  }
};