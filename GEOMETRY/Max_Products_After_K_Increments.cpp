#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;
  int maximumProduct(vector<int>& nums, int k) {
    
    // Out of all rectangles, area of square is max
    // Ex :  [2,4] = 2*4 = 8
    //       [2,6] = 2*6 = 12, Incremented 4 + 2 = 6
    //       [4,4] = 4*4 = 16,             2 + 2 = 4, Overall area increased
    // Reduce diff b/w max & min element

    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &x : nums)
      pq.push(x);

    while(k > 0){
      int mn = pq.top();
      pq.pop();

      pq.push(mn + 1);
      k--;
    }    

    long long ans = pq.top();
    pq.pop();

    while(!pq.empty()){
      ans = (ans * pq.top()) % MOD;
      pq.pop();
    }

    return ans;
  }
};