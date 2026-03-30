#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N)
//! SC = O(N)
//! HashMap

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
    unordered_map<int,int> m;
    int n = nums.size();

    for(int i = 0; i < n; i++){
      m[nums[i]]++;
    }    

    vector<int> ans;
    for(auto &it : m){
      if(it.second > n/3){
        ans.push_back(it.first);
      }
    }

    return ans;
    }
};

