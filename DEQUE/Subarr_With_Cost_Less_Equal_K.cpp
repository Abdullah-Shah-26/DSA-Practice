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
    long long countSubarrays(vector<int>& a, long long k) {
     long long cnt = 0;
    int n = a.size();
    deque<int>dqMin,dqMax;
    int l = 0;
    for(int r = 0; r < n; r++){
      
      while(!dqMax.empty() && a[r] > dqMax.back()){
        dqMax.pop_back();
      }
      dqMax.push_back(a[r]);
      
      while(!dqMin.empty() && a[r] < dqMin.back()){
        dqMin.pop_back();
      }
      dqMin.push_back(a[r]);

      while(!dqMax.empty() && !dqMin.empty() && 1LL * (dqMax.front() - dqMin.front())*(r-l+1) > k){
        if(dqMax.front() == a[l]) dqMax.pop_front();
        if(dqMin.front() == a[l]) dqMin.pop_front();
        l++;
      }
      cnt += (r - l + 1);
    }

    return cnt;    
    }
};