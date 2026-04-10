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
    int halveArray(vector<int>& nums) {
    double sum = 0;

    for(auto &x : nums){
      sum += x;
    }    
    
    double target = sum/2.0;

    priority_queue<double> pq(begin(nums), end(nums)); //O(N)

    int cnt = 0;

    while(!pq.empty() && sum > target){
      double maxi = pq.top();
      pq.pop();

      sum -= (maxi/2.0);

      pq.push(maxi/2.0);
      cnt++;
    }

    return cnt;
    }
};