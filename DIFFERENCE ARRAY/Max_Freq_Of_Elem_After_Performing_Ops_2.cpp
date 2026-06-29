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
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int maxElem = *max_element(begin(nums), end(nums));
    int maxValue = maxElem + k;
    int n = nums.size();
    map<int,int> diff;  // Differance Array Technique
    unordered_map<int,int> freq;    

    // TC = O(maxValue + N*LogN)
    // SC = O(2*N)
    for(int i = 0; i < n; i++){
      freq[nums[i]]++;

      int l = max(0, nums[i] - k);
      int r = min(nums[i] + k, maxValue);

      diff[l] += 1;
      diff[r + 1] -= 1;

      diff[nums[i]] += 0; // Important Step
    }

    int result = 1;
    int cumSum = 0; // Find CumSum

    for(auto &it : diff){
      int target = it.first;

      cumSum += it.second;// Prefix Sum First
      int coverage = cumSum;

      int targetFreq = freq[target];
      int needConversion = coverage - targetFreq;
      int canConvert = min(needConversion, numOperations);

      result = max(result, targetFreq + canConvert);
    }
    return result;
    }
};