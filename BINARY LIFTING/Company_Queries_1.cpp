#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int up[200005][30];

int jump(int node, int k){
  for(int bit = 0; bit < 30; bit++){
    if(k & (1 << bit)){
        node = up[node][bit];
        if(node == -1){
          break;
        }
    }
  } 
  return node;
}
//! TC = (n + Q)Log N = (n + Q)Log(1e9) = (n + Q)*30
//! SC = O(n LogN)
void solve(){
  int n, q;
  cin >> n >> q;

  memset(up, -1, sizeof(up));
 
  //! TC = O(n)
  for(int i = 2; i <=  n; i++){
    // Filing up immediate parents
    cin >> up[i][0];
  
  }

  //! TC = O(n * 30)
  // Precomputing all k ancestors
  for(int k = 1; k < 30; k++){
    for(int node = 1; node <= n; node++){
      if(up[node][k-1] != -1)
      up[node][k] = up [ up[node][k-1] ][k-1];
    }
  }
  //! TC = O(Q LogN)
  // processing queries
  while(q--){
    int node, k;
    cin >> node >> k;

    cout << jump(node, k) << "\n";
  }

  return;
}

int main(){

  solve(); 
  return 0;   
}