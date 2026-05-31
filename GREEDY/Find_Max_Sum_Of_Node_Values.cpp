#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
  long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
  ll sum = 0;
  ll gain = 0;
  ll minLoss = LLONG_MAX;
  ll cnt = 0;
  
  for(auto x : nums){
    sum += x;
    if((x ^ k) > x){
      cnt++;
      gain += (x^k) - x;
    }
    minLoss = min(minLoss, (ll)abs((x ^ k) - x));
  }    

  if(cnt % 2 == 0)
    return sum + gain;

  return sum + gain - minLoss;
  }
};