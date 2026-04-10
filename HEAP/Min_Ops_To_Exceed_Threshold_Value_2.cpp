#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(NLogN) || SC = O(N)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(begin(nums), end(nums)); // O(N) - Heapify

    int cnt = 0;   

    while(!pq.empty() && pq.top() < k){
      long long mini1 = pq.top(); pq.pop();
      long long mini2 = pq.top(); pq.pop();

      pq.push(mini1 * 2 + mini2);

      cnt++;
    }

    return cnt;
    }
};