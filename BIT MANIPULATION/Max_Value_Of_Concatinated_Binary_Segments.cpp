#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

//* TC = O(NLogN + N*L)

class Solution {
  public:
  // We are building from R to L
  // Process bad guys first, since we are building from LSB -> MSB
    static bool cmp(const pair<int,int> &a, const pair<int,int> &b){
      if(a.second == 0) return false; // 111... push to R
      if(b.second == 0) return true; // 000... push to L

      if(a.first == b.first)
        return a.second > b.second;

      return a.first < b.first;

    }

    int maxValue(vector<int>& ones, vector<int>& zeros) {
    int n = ones.size();

    vector<pair<int,int>> blocks(n);

    for(int i = 0; i < n; i++){
      blocks.push_back({ones[i], zeros[i]});
    }

    sort(blocks.begin(), blocks.end(), cmp);

    ll ans = 0;
    ll pw = 1;

    for(auto [ones, zeros] : blocks){

      // shift for zeros
      while(zeros--){
        pw = (pw * 2) % MOD;
      }

      // place ones
      while(ones--){
        ans = (ans + pw) % MOD;
        pw = (pw * 2) % MOD;
      }

    }

    return ans;
    }
};