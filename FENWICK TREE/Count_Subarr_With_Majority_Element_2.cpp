#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Fenwick Tree + Co - ordinate Compresssion

class Fenwick{
  public:

  int n;
  vector<int> bit;

  Fenwick(int n) : n(n), bit(n + 1, 0){}

  void update(int i, int val){
    while(i <= n){
      bit[i] += val;
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
    long long countMajoritySubarrays(vector<int>& nums, int target) {
      int n = nums.size();

      for(auto &x : nums){
        if(x == target) x = 1;
        else x = -1;
      }

      vector<int> pref(n + 1, 0);

      for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + nums[i - 1];
      }

      // Co-ordinate Compression
      vector<int> vals = pref;
      sort(vals.begin(), vals.end());
      vals.erase(unique(vals.begin(), vals.end()), vals.end());

      int m = vals.size();

      Fenwick ft(m);

      // Id = compressed index of pref value
      auto getId = [&](int x){
        // +1 Since Fenwick Tree is 1 based
        return lower_bound(begin(vals), end(vals), x) - vals.begin() + 1;
      };

      ft.update(getId(pref[0]), 1);

      long long ans = 0;

      for(int j = 1; j <= n; j++){
        int id = getId(pref[j]);

        if(id > 0){
          // Cnt guys strictly smaller than pref[j] in range [0....j-1]
          ans += ft.query(id-1);
        }

        ft.update(id, 1);
      }

      return ans;
    }
};