#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N)
//! SC = O(1)

class Solution {
  public:
    int maxChunksToSorted(vector<int>& a) {    
    int chunks = 0;
    int cumSum = 0;
    int sortedSum = 0;
    for(int i = 0; i < a.size(); i++){
      cumSum += a[i];
      sortedSum += i;

      if(cumSum == sortedSum){
        chunks++;
      }
    }
    return chunks;
    }
};

class Solution {
  public:
    int maxChunksToSorted(vector<int>& a) {    
    int chunks = 0;
    int maxSoFar = 0;

    for(int i = 0; i < a.size(); i++){
      maxSoFar = max(maxSoFar, a[i]);

      if(i == maxSoFar){
        chunks++;
      }
    }
    return chunks;
    }
};