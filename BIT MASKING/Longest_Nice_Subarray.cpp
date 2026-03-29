#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N^2)
//! SC = O(1)

class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
    int n = a.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++){
      int mask = 0;
      for(int j = i; j < n; j++){
        if((mask & a[j]) != 0){
          break;
        }
        else{
          mask |= a[j];
          maxLen = max(maxLen, j - i + 1);
        }
      }
    }
    return maxLen;
    }
};

//! TC = O(N)
//! SC = O(1)

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0;
    int maxLen = 1;
    int mask = 0;

    while(j < n){

      // Invalid - Shrink
      while((mask & nums[j]) != 0){
        mask ^= nums[i];
        i++;
      }

      maxLen = max(maxLen, j - i + 1);      
      mask |= nums[j];
      j++;
    }

    return maxLen;

    }
};