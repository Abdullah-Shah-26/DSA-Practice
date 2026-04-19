#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(32) = O(1) constant
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

//! Reverse Until Highest Bit is set
/*
Ex:
Input  :  11 - 1011
Output :  13 - 1101

GFG Version
*/

//! TC = O(Log N)
//! SC = O(1)
class Solution{
  public: 

  unsigned int reverseBits(unsigned int n){
    unsigned int res = 0;

    while(n > 0){
      res <<= 1;
      res |= (n & 1);
      n >>= 1;
    }

   return res;
  }
};