#include <bits/stdc++.h>
using namespace std;

// TC = O(QLogQ) | SC = O(Q)

class Fenwick{
public:
  int n;
  vector<int> bit;

  Fenwick(int n){
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void update(int i, int val){
    while(i <= n){
      bit[i] = max(bit[i], val);
      i += (i & -i);
    }
  }

  int query(int i){
    int ans = 0;
    while(i > 0){
      ans = max(ans, bit[i]);
      i -= (i & -i);
    }
    return ans;
  }
};

class Solution {
public:
  vector<bool> getResults(vector<vector<int>>& queries) {
  int maxX = 0;

  // Finding max - cordinate
  for(auto &q : queries)
    maxX = max(maxX, q[1]);

  set<int> obstacles;

  obstacles.insert(0);
  obstacles.insert(maxX);

  // Final obstacle state
  for(auto &q : queries){
    if(q[0] == 1){
      int obstaclePos = q[1];
      obstacles.insert(obstaclePos);
    }
  }

  Fenwick ft(maxX + 1);

  auto curIt = obstacles.begin();
  curIt++;

  // Now curIt is at 2nd obstacle
  while(curIt != obstacles.end()){
    int rightObs = *curIt;
    int leftObs = *prev(curIt);
    int gap = rightObs - leftObs;
    
    ft.update(rightObs + 1, gap); // Store gap ending at right obstacle
    curIt++;
  }

  vector<bool> ans;

  for(int i = queries.size() - 1; i >= 0; i--){
    vector<int> &q = queries[i];
    if(q[0] == 1){ // Remove obstacle
      int obstaclePos = q[1];

      auto obsIt = obstacles.find(obstaclePos);
      int leftObs = *prev(obsIt);
      int rightObs = *next(obsIt);
      int mergedGap = rightObs - leftObs;

      ft.update(rightObs + 1, mergedGap); // Store merged gap

      obstacles.erase(obsIt);
    }
    else{ // Query
      int x = q[1];
      int reqSize = q[2];

      // Max gap ending before or at x - Full Gaps
      int bestGap = ft.query(x + 1);

      // Finding obstacle
      auto it = obstacles.upper_bound(x);
      it--; // <= x

      int prevObs = *it;
      int tailGap = x - prevObs; // Partial Gap 

      bestGap = max(bestGap, tailGap);

      ans.push_back(bestGap >= reqSize);
    }
  }
  
  reverse(begin(ans),end(ans));

  return ans;
  }
};