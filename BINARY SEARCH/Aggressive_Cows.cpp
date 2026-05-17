#include <bits/stdc++.h>
using namespace std;

// TC = O(N * LogN) + O(N LogD)
// SC = O(1)

class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        auto canPlace = [&](int dist) {
            int cows = 1, last = stalls[0];
            
            for(int i = 1; i < stalls.size(); i++) {
                if(stalls[i] - last >= dist) {
                    cows++;
                    last = stalls[i];
                }
            }
            
            return cows >= k;
        };
        
        int lo = 1, hi = stalls.back() - stalls.front();
        int ans = 0;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(canPlace(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};