#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! SPF
//* TC = (A Log(Log(A))) + N*A
//* SC = O(A)

class Solution {
public:
    void buildSPF(vector<int> &spf, int maxi){
      for(int i = 0; i <= maxi; i++){
        spf[i] = i;
      }

      for(int i = 2; i*i <= maxi; i++){
        if(spf[i] == i){ // Its prime, mark guys that it divides
          for(int j = i*i; j <= maxi; j+=i){
            if(spf[j] == j){// Unmarked
              spf[j] = i; // Mark It
            }
          }
        }
      }
    }

    int distinctPrimeFactors(vector<int>& nums) {
    int n = nums.size();
    int maxi = *max_element(begin(nums), end(nums));

    vector<int> spf(maxi + 1, -1);
    buildSPF(spf, maxi);
  
    vector<bool> seen(maxi + 1, 0); // stores unique factors seen so far

    int unique = 0;

    for(int i = 0; i < n; i++){
      int x = nums[i];

      while(x > 1){
        int factor = spf[x];

        if(!seen[factor]){
          seen[factor] = 1;
          unique++;
        }

        while(x % factor == 0){
          x /= factor;
        }
      }
    }

    return unique;
    }
};