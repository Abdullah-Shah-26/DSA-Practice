#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Prefix XOR 
using ll = long long;
class Solution {
public:
    long long wonderfulSubstrings(string word) {
    ll freq[1024] = {0};
    freq[0] = 1;
    int cumXor = 0;

    ll res = 0;
    // TC = O(Len of Word)
    // SC = O(1)
    for(char &ch : word){
      int shift = ch - 'a';

      cumXor ^= (1 << shift);

      res += freq[cumXor];

      for(char ch = 'a'; ch <= 'j'; ch++){

        shift = ch - 'a';

        ll checkXor = (cumXor ^ (1 << shift));

        res += freq[checkXor]; 
      }
      freq[cumXor]++;
    } 

    return res;   
    }
};