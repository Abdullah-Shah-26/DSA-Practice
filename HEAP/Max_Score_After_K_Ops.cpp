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
    long long maxKelements(vector<int>& nums, int k) {
    priority_queue<long long> pq(begin(nums), end(nums)); // MaxHeap // O(N)

    long long score = 0;

    while(!pq.empty() && k--){ // (K Log N)
      long long maxi = pq.top();
      pq.pop();  

      score += maxi;

      maxi = ceil(maxi/3.0);

      pq.push(maxi);
    } 

    return score;   
    }
};