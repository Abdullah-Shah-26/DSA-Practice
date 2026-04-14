#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N) | SC = O(N)

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
    int cnt = target[0];
    int n = target.size();
    
    // Local Optimal == Global Optimal

    for(int i = 1; i < n; i++){
      if(target[i] > target[i-1]){
        cnt += (target[i] - target[i-1]);
      }
    }    

    return cnt;
    }
};