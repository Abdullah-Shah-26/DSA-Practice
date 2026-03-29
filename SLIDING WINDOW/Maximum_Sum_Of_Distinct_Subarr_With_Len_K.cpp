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

class Solution{
  public:
    ll maxSubarrSum(vector<int> &a, int k){
      ll curSum = 0;
      ll maxSum = 0;
      int n = a.size();

      unordered_map<int,int> m;
      
      int l = 0, r = k - 1;
      int distinct = 0;

      for(int i = l; i <= r; i++){
        m[a[i]]++;
        
        if(m[a[i]] == 1) distinct++;

        curSum += a[i];
      }

      for(int end = k - 1; end < n; end++){
        // Valid Check
        if(distinct == k){
          maxSum = max(maxSum, curSum);
        }

        // Remove L 
        curSum -= a[l];
        m[a[l]]--;
        if(m[a[l]] == 0) distinct--;
        l++;

        // Add R
        r++;
        if(r == n) continue;

        curSum += a[r];
        m[a[r]]++;
        if(m[a[r]] == 1) distinct++;
      }

      return maxSum;
    } 
};