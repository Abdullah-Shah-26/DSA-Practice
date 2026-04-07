#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC  = (1e5 Log(Log(1e5))) || SC = O(1e5)

class Solution {
public:
    int maxi = 100000;
    int spf[100001];
    void buildSPF(){
      for(int i = 0; i <= maxi; i++) spf[i] = i;

      for(int i = 2; i * i <= maxi; i++){
        if(spf[i] == i){
          for(int j = i*i; j <= maxi; j+=i){
            if(spf[j] == j){
              spf[j] = i;
            }
          }
        }
      }
    }

    int getSum(int x){
      int sum = 0;

      while(x > 1){
        int factor = spf[x];
        sum += factor;
        x /= factor;
      }
      return sum;
    }

    int smallestValue(int n) {
    buildSPF();

    while(true){
      int sum = getSum(n);
      if(sum == n) break;
      n = sum;
    }

    return n;
    }
};