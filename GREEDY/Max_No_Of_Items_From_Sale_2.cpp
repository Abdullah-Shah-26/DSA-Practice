#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
  int maximumSaleItems(vector<vector<int>>& items, int budget) {
  int n = items.size();

  int maxF = 0; // Max factor 
  int minP = 2e9; // Min price

  for(auto &it : items){
    maxF = max(maxF, it[0]);
    minP = min(minP, it[1]);
  }

  vector<int> freq(maxF + 1, 0);
  for(auto &it : items){
    freq[it[0]]++;
  }

  vector<int> cnt(maxF + 1, 0); // Cnt of free copies each factor can get
  for(int i = 1; i <= maxF; i++){
    if(freq[i] == 0) continue; 

    for(int j = i; j <= maxF; j+=i)
      cnt[i] += freq[j];                      
  }

  vector<pair<ll, ll>> vec;
  for(auto &it : items){
    ll factor = it[0], price = it[1];
    ll freeCopies = cnt[factor] - 1; // Excluding itself
    
    if(freeCopies > 0 && price < 2 * minP)
      vec.push_back({price,  freeCopies});
  }

  sort(begin(vec), end(vec));

  ll ans = 0, left = budget; // Budget left
  for(auto &[price, cnt] : vec){
    ll take = min(cnt, left/price);
    ans += 2 * take;
    left -= take * price;
    if(take < cnt) break;
  }

  // If budget left, buy item with least price
  ans += left/minP;

  return ans;
  }
};

