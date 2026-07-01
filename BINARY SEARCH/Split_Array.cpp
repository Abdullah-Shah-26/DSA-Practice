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

// Splits Never Increase Subarr Sum so check feasibilty <= k
  bool isPossible(long long x, int k, vector<int>& nums) {
    long long curSum = 0;
    int subarrays = 1;
    
    for (int num : nums) {
      if (num > x) return false;
      
      if (curSum + num > x) {
        subarrays++;
        curSum = num;
      } else {
        curSum += num;
      }
    }
    return subarrays <= k;
  }

  int splitArray(vector<int>& nums, int k) {
    long long low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0LL);
    long long ans = high;

    while (low <= high) { // TC = O(N*Log(Range))
      long long mid = (low + high) / 2;
      
      if (isPossible(mid, k, nums)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return (int)ans;
  }
};