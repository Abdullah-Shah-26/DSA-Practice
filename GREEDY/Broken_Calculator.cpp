#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(Log (end)) || SC = O(1)

class Solution {
public:
    int brokenCalc(int s, int e) {
    int steps = 0;

    while(e > s){
      if((e & 1) == 0) e = e/2;
      else e += 1;
      steps++;
    }

    return steps + (s - e);
    }
};