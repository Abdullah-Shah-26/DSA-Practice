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

//! TC = O(N)
//! SC = O(1)

//! Moores Voting Modified

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;
    int elem1 = INT_MIN, elem2 = INT_MIN;

    for(int i = 0; i < n; i++){
      
      if(cnt1 == 0 && nums[i] != elem2){
        cnt1 = 1;
        elem1 = nums[i]; 
      }
      else if(cnt2 == 0 && nums[i] != elem1){
        cnt2 = 1;
        elem2 = nums[i];
      }
      else if(nums[i] == elem1) cnt1++;
      else if(nums[i] == elem2) cnt2++;
      else{
        cnt1--;
        cnt2--;
      }
    }        

    cnt1 = 0, cnt2 = 0;
    for(auto &i : nums){
      if(i == elem1) cnt1++;
      if(i == elem2) cnt2++;
    }

    vector<int> ans;

    if(cnt1 > n/3) ans.push_back(elem1);
    if(cnt2 > n/3) ans.push_back(elem2);

    return ans;
    }
};