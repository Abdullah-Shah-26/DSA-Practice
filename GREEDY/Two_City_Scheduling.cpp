#include <bits/stdc++.h>
using namespace std;

using T = tuple<int,int,int>;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size();

    vector<T> net;

    for(int i = 0; i < n; i++){
      net.push_back({
        costs[i][1] - costs[i][0],
        costs[i][0],
        costs[i][1]
      });
    }

    sort(begin(net), end(net));

    int A = 0, B = 0;
    int cntB = 0;

    // Smaller (B-A), sending b is better
    // Larger (B-A), sending a is better

    for(int i = 0; i < n; i++){
      auto [gross, a, b] = net[i];

      if(cntB < n / 2){
        cntB++;
        B += b;
      }
      else{
        A += a;
      }
    }

    return A + B;
  }
};