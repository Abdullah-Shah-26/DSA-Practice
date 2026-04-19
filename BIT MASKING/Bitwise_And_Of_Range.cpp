#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(LogN)
//! SC = O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    int shiftCnt = 0;
    while(left != right){
      left >>= 1;
      right >>= 1;
      shiftCnt++;
    }    
    return (left << shiftCnt);
    }
};

class Solution {
public:
//! TC = O(No of Bits) = O(32)
    int rangeBitwiseAnd(int left, int right) {
    while(right > left){
      right = right & (right - 1);
    }
    return right;
    }
};