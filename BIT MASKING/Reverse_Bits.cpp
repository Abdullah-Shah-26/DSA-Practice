#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(Log N)
//! SC = O(1)
class Solution {
public:
    int reverseBits(int n) {
    int ans = 0;
    
    for(int i = 0; i < 32; i++){
      ans <<= 1;
      ans |= (n & 1);
      n >>= 1;
    }
    
    return ans;
    }
};