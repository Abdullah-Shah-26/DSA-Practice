#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// Sliding Window
class Solution {
  public:
    int atmost(vector<int>&arr, int k){
        if(k < 0){
            return 0;
        }
        int n = arr.size();
        int l = 0, r = 0;
        int cnt = 0;
        int ans = 0;
        while(r < n){
            if(arr[r] & 1){
                cnt++;
            }
            while(cnt > k && l <= r){
                if(arr[l] & 1){
                    cnt--;
                }
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
  
    int countSubarrays(vector<int>& arr, int k) {
    return atmost(arr, k) - atmost(arr, k - 1);
    }
};
// Prefix Sum 
class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
    unordered_map<int,int>freq;
    freq[0]  = 1;
    int oddCnt = 0;
    int ans =  0;
    
    for(int x : arr){
        if(x & 1){
            oddCnt++;
        }
        
        if(freq.count(oddCnt - k)){
            ans+= freq[oddCnt - k];
        }
        freq[oddCnt]++;
    }
    return ans;
    }
};