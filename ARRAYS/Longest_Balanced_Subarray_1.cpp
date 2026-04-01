#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N^2)
//! SC = O(N + N)

//! Range queries can be optimized using segment trees

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;

    unordered_map<int,int> m;
    vector<long long> cumSum(n,0);

    for(int r = 0; r < n; r++){
      // Odd - Change to -1
      // Even - Change to +1
      int value = (nums[r] & 1) ? -1 : 1;
      
      int prev = -1;

      if(m.count(nums[r])){
        // Have seen this guy before
        prev = m[nums[r]];
      }

      if(prev != -1){ // To prevent Duplicates
        for(int l = 0; l <= prev; l++){
          cumSum[l] -= value;
        }
      }

      for(int l = 0; l <= r; l++){
        cumSum[l] += value;
      }

      for(int l = 0; l <= r; l++){
        if(cumSum[l] == 0){
          maxLen = max(maxLen, r - l + 1);
          break; // Finding least l to maximize len so break early
        }
      }

      m[nums[r]] = r;
    }    

    return maxLen;
    }
};