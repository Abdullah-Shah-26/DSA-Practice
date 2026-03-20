#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    //! TC = (N*32)
    //! SC = O(32)
    vector<int> smallestSubarrays(vector<int>& nums) {
    int n = nums.size();

    // Stores nearest i to set the jth bit
    vector<int> setBitIdx(32, -1);
    vector<int> result(n, 0);

    for(int i = n-1; i >= 0; i--){
      int nearestIdx = i;
      for(int j = 0; j < 32; j++){
        if(!(nums[i] & (1 << j))){
          if(setBitIdx[j] != -1){
            nearestIdx = max(nearestIdx, setBitIdx[j]);
          }
        } else {
          setBitIdx[j] = i;
        }
      }
    result[i] = nearestIdx - i + 1;
    }
    return result;
    }
};