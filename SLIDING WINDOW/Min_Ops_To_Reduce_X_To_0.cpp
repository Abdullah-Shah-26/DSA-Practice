#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N) ||  SC = O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    int sum = 0;
    int n = nums.size();

    for(auto &i : nums){
      sum += i;
    }   

    int target = sum - x;

    if(target < 0) return -1; // Can't chnage x to 0 even after using all elements
    if(target == 0) return n; // remove all elements

    int l = 0; 
    int curSum = 0;
    int maxLen = -1;
    
    for(int r = 0; r < n; r++){
      curSum += nums[r];

      while(curSum > target){
        curSum -= nums[l];
        l++;
      }

    if(curSum == target)
      maxLen = max(maxLen, r-l+1);
    }

    if(maxLen == -1) return -1;

    return n - maxLen;
    }
};