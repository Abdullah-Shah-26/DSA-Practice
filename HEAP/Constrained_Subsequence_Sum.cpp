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
    int constrainedSubsetSum(vector<int>& nums, int k) {
    
    int n = nums.size();
    int res = nums[0];

    priority_queue<pair<int,int>> pq;
    
    pq.push({nums[0],0});

    for(int i = 1; i < n; i++){
    while(!pq.empty() && pq.top().second < i - k){
        pq.pop();
    }

    int best = pq.empty() ? 0 : max(0,pq.top().first);

    int curMax = max(nums[i], nums[i] + best);

    res = max(res, curMax);

    pq.push({curMax, i});
}
    return res;
    }
};
