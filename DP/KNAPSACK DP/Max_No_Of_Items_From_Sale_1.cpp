#include <bits/stdc++.h>
using namespace std;

// DP + Greedy
// Take/Skip one item of each type so that we get freeCopies of their multiples
// After considering all choices if budget is left, take Item which has minPrice

class Solution {
public:
  int n, minPrice;
  vector<vector<int>> dp;

  // TC = O(N * Budget)
  int f(int i, int budget, vector<pair<int, int>> &nItems,
        vector<int> &freeCopies) {
    if (i == n)
      return budget / minPrice;

    if (dp[i][budget] != -1)
      return dp[i][budget];

    auto [factor, price] = nItems[i];

    int skip = f(i + 1, budget, nItems, freeCopies);

    int take = 0;
    if (budget >= price) {
      take = f(i + 1, budget - price, nItems, freeCopies) + freeCopies[i] + 1;
    }

    return dp[i][budget] = max(take, skip);
  }

  int maximumSaleItems(vector<vector<int>> &items, int budget) {
    vector<pair<int, int>> nItems;
    minPrice = 1501;

    for (auto &vec : items) {
      nItems.push_back({vec[0], vec[1]}); // factor, price
      minPrice = min(minPrice, vec[1]);
    }

    n = items.size();
    dp.assign(n, vector<int>(budget + 1, -1));

    vector<int> freeCopies(n, 0);

    for (int i = 0; i < n; i++) { // TC = O(N ^ 2)
      auto [factorI, priceI] = nItems[i];

      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;

        auto [factorJ, priceJ] = nItems[j];

        if (factorJ % factorI == 0)
          freeCopies[i]++;
      }
    }

    return f(0, budget, nItems, freeCopies);
  }
};

// Bottom Up

class Solution {
public:
  int n, minPrice;
  vector<vector<int>> dp;

  int maximumSaleItems(vector<vector<int>>& items, int budget) {
  vector<pair<int,int>> nItems;
  minPrice = 1501;

  for(auto &vec : items){
    nItems.push_back({vec[0], vec[1]}); // factor, price
    minPrice = min(minPrice, vec[1]);
  }    

  n = items.size();
  dp.assign(n + 1, vector<int> (budget + 1, 0));

  // Base case init : 
  for(int b = 0; b <= budget; b++){
    dp[n][b] = b/minPrice;
  }

  vector<int> freeCopies(n, 0);

  for(int i = 0; i < n; i++){
    auto [factorI, priceI] = nItems[i];

    for(int j = 0; j < n; j++){
      if(i == j) continue;

      auto [factorJ, priceJ] = nItems[j];

      if(factorJ % factorI == 0)
        freeCopies[i]++; 
    }
  }

  for(int i = n-1; i >= 0; i--){
    for(int b = 0; b <= budget; b++){
      auto [factor, price] = nItems[i];
      int skip = dp[i + 1][b];
      int take = 0;
      if(price <= b)
        take = dp[i + 1][b - price] + freeCopies[i] + 1;
      
      dp[i][b] = max(take, skip);
    }
  }

  return dp[0][budget];
  }
};