#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Fenwick{
  public:

  ll n;
  vector<ll> bit;

  Fenwick(ll n) : n(n), bit(n + 1, -1e18){}

  void update(ll idx, ll val){
    while(idx <= n){
      bit[idx] = max(bit[idx], val);
      idx += (idx & -idx);
    }
  }

  ll query(ll idx){
    ll maxi = -1e18;
    while(idx > 0){
      maxi = max(maxi, bit[idx]);
      idx -= (idx & -idx);
    }
    return maxi;
  }
};

class Solution {
public:  
  long long maxAlternatingSum(vector<int>& nums, int k) {
  ll n = nums.size();

  // Co-ordinate compression
  vector<int> arr = nums;
  sort(begin(arr), end(arr));
  arr.erase(unique(begin(arr), end(arr)), arr.end());  
  
  ll m = arr.size();
  Fenwick pref(m);
  Fenwick suff(m);
  
  vector<ll> dp1(n, 0);
  vector<ll> dp2(n, 0);
  
  ll ans = -1e18;

  for(int i = 0; i < n; i++){
    if(i >= k){
      auto it = lower_bound(begin(arr), end(arr), nums[i - k]);
      ll idx = it - arr.begin() + 1; // Since Ft is 1-based
      pref.update(idx, dp1[i - k]);
      suff.update(m - idx + 1, dp2[i - k]);
    }

    auto it = lower_bound(begin(arr), end(arr), nums[i]);
    ll idx = it - begin(arr) + 1;

    ll maxPref = pref.query(idx - 1);
    ll maxSuff = suff.query(m - idx + 1 - 1);
  
    dp1[i] = nums[i] + max(0LL, maxSuff);
    dp2[i] = nums[i] + max(0LL, maxPref);

    ans = max({ans, dp1[i], dp2[i]});  
  }

  return ans;
  }
};