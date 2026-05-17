#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

// TC = O(N log N + N) SC = O(1)

class Solution {
  public:
    long long solve(vector<int>& bt) {
    
    sort(bt.begin(), bt.end());
    long long t = 0, wtTime = 0;
    
    for(int i = 0; i < bt.size(); i++)
    {
        wtTime += t;
        t += bt[i];
    }
        return wtTime/bt.size();
    }
};
 

