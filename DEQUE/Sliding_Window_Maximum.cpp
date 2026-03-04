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
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int>list;
    deque<int>dq;
// Monotonic Decreasing Deque
    for(int i=0; i<n; i++){
      if(!dq.empty() && dq.front() <= i-k){
        dq.pop_front();
      }
      while(!dq.empty() && arr[dq.back()] <= arr[i]){
        dq.pop_back();
      }
      dq.push_back(i);
      if(i >= k-1){
        list.push_back(arr[dq.front()]);
      }
    }

    return list;
    }
};  