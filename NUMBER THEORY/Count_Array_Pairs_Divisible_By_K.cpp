#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countPairs(vector<int>& nums, int k) {
    
  long long ans = 0;
  unordered_map<int,int> freq;

  for(int x : nums){
    long long g = gcd(x, k);

    // Cnt all valid prev groups
    for(auto &[oldGcd, cnt] : freq){
      if((oldGcd * g) % k == 0)
        ans += cnt;
    }

    freq[g]++;
  }

  return ans;
  }
};
