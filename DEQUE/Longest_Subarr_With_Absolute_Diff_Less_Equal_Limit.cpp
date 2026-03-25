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
    int longestSubarray(vector<int>& a, int k) {
    int n = a.size();
    int maxLen = 0;
    deque<int> dqMax,dqMin;
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

      while(!dqMax.empty() && !dqMin.empty() && dqMax.front() - dqMin.front() > k){
        if(a[l] == dqMax.front()) dqMax.pop_front();
        if(a[l] == dqMin.front()) dqMin.pop_front();
        l++;
      }
      maxLen = max(maxLen, r - l + 1);
    }    
    return maxLen;
    }
};