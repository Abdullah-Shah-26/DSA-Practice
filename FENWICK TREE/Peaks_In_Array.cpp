#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O((N + Q) LogN)
//! SC = O(N + Q)

class Fenwick{
  public:
    int n;
    vector<int> bit;

    Fenwick(int n): n(n), bit(n+1,0) {}

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

    int rangeQuery(int l,int r){
      if(l > r) return 0;
      return query(r) - query(l-1);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
      int n = nums.size();

      Fenwick ft(n);

      auto isPeak = [&](int &i){
        return nums[i] > nums[i-1] && nums[i] > nums[i+1];
      };

      vector<int> peak(n,0);
 
      for(int i = 1; i < n-1; i++){
        if(isPeak(i)){
          peak[i] = 1;
        }
      }

      // Fenwick O(1) Build
      for(int i = 0; i < n; i++){
        ft.bit[i+1] = peak[i];
      }

      for(int i = 1; i <= n; i++){
        int parent = i + (i & -i);
        
        if(parent <= n)
          ft.bit[parent] += ft.bit[i];
      }

      vector<int> ans;

      for(auto &q : queries){
        if(q[0] == 1){
          int l = q[1], r = q[2];

          if(l + 1 <= r - 1){
            // Fenwick is 1 based
            ans.push_back(ft.rangeQuery(l+1 + 1, r-1 + 1));
          }
          else{
            ans.push_back(0);
          }
        }
        else{
          int pos = q[1], val = q[2];

          nums[pos] = val;

          for(int i = pos-1; i <= pos+1; i++){
            if(i > 0 && i < n-1){
              int newVal = isPeak(i);

              if(peak[i] != newVal){
                // Fenwick is 1 based 
                // We cannot overwrite but we can simulate overwrite
                // delta = newValue - oldValue
                ft.update(i+1, newVal - peak[i]);
                peak[i] = newVal;
              }
            }
          }
        }
      }

      return ans;
    }
};