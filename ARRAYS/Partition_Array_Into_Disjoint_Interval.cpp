#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N)
//! SC = O(N)

class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
    int n = a.size();
    vector<int> prefMax(n,0), suffMin(n,INT_MAX);

    prefMax[0] = a[0];
    for(int i = 1; i < n; i++){
      prefMax[i] = max(prefMax[i-1], a[i]);
    }    

    suffMin[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
      suffMin[i] = min(suffMin[i + 1], a[i]);
    }

    for(int i = 0; i < n - 1; i++){
      if(prefMax[i] <= suffMin[i+1]){ // First Valid Partition Point
        return i + 1; 
      }
    }
    
    return n;
    }
};

//! TC = O(N)
//! SC = O(1)

class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
    int leftMax = a[0];    
    int globalMax = a[0];
    int pos = 0;

    for(int i = 1; i < a.size(); i++){
      globalMax = max(globalMax, a[i]);

      if(a[i] < leftMax){ // Should belong to left Partition
        pos = i;
        leftMax = globalMax;
      }
    }

    return pos + 1;
    }
};