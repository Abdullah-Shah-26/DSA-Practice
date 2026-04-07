#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = N(Log(Log(N)))   ||  N = maxElement
//* SC = O(N)

void buildSPF(vector<int> &spf, int maxi){
  for(int i = 0; i <= maxi; i++) spf[i] = i;
 
  for(int i = 2; i*i <= maxi; i++){
    if(spf[i] == i){
      for(int j = i*i; j <= maxi; j += i){
        if(spf[j] == j){
          spf[j] = i;
        }
      }
    }
  }
}

int main(){
  fastio();
  
  int maxi = 1e5;
  vector<int> spf(maxi + 1);

  buildSPF(spf, maxi);

  //* Prime Factors of 50

  int x = 50;
  while(x > 1){
    int factor = spf[x];

    cout << factor << " " << endl;

    while(x % factor == 0){
      x /= factor;
    }
  }
}