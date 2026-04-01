#include <bits/stdc++.h>
using namespace std;

// Fenwick + Co-ordinate compression
class Fenwick{
  public: 
  int n;
  vector<int> bit;

  Fenwick(int N){
    n = N;
    bit.resize(n + 1, 0);
  }

  void update(int i, int delta){
    while(i <= n){
      bit[i] += delta;
      i = i + (i & -i);
    }
  }

  int query(int i){
    int sum = 0;

    while(i > 0){
      sum += bit[i];
      i = i - (i & -i);
    }

    return sum;
  }
};

class Solution {
public:
    using ll = long long;
    int reversePairs(vector<int>& nums) {
    int n = nums.size();

    vector<ll> vals;

    for(auto &x: nums){
      vals.push_back(x);
      vals.push_back(2LL *x);
    }   

    sort(begin(vals), end(vals));
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();

    Fenwick ft(m);

    ll ans = 0;

    for(int j = 0; j < n; j++){
      ll x = nums[j];

      ll target = 2 * x;
      
      int id = upper_bound(vals.begin(), vals.end(), target) - vals.begin();

      // elem > 2*x = total - elem <= 2*x
      ans += ft.query(m) - ft.query(id);

      int pos = lower_bound(vals.begin(), vals.end(), x) - vals.begin();

      ft.update(pos + 1, 1);
    }
    
    return ans;
    }
};