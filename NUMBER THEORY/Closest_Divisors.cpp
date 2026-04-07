#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(sqrt(N)) || SC = O(1)

class Solution {
public:
    vector<int> solve(int x){
      for(int i = sqrt(x); i >= 1; i--){
        if(x % i == 0){
          return {i, x/i};
        }
      }
      return {1,x};
    }

    vector<int> closestDivisors(int num) {
      auto a = solve(num + 1);
      auto b = solve(num + 2);

      if(abs(a[0] - a[1]) < abs(b[0] - b[1])){
        return a;
      }
      return b;
    }
};
