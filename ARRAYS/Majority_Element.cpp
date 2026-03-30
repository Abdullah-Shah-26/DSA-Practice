#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Brute Force
//! TC = O(N^2)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++){
      int cnt = 0;
      for(int j = 0; j < n; j++){
        if(nums[i] == nums[j]){
          cnt++;
        }
      }
      if(cnt > n/2){
        return nums[i];
      }
    }

    return -1;
    }
};

//! HashMap

//! TC = O(N)
//! SC = O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int>m;

    for(int i = 0; i < n; i++){
      m[nums[i]]++;
    }

    for(auto &it : m){
      if(it.second > n/2){
        return it.first;
      }
    }
    
    return -1;
    }
};

//! Moores Voting Algorithm

//! TC = O(N)
//! SC = O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums){
    int n = nums.size();
    int majorityElem;
    int cnt = 0;

    for(int i = 0; i < n; i++){

      if(cnt == 0){
        cnt = 1;
        majorityElem = nums[i];
      }
      else if(nums[i] == majorityElem){
        cnt++;
      }
      else{
        cnt--;
      }

    }

    return majorityElem;
    }
};