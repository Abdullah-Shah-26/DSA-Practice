#include <bits/stdc++.h>
using namespace std;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! For Static Range Min Query 
//! TC = O(N Log N + Q)
//! SC = O(N Log N)
// Per Query - O(1)

struct sparseTable{
  int n, LOG;
  vector<vector<int>> st;

  sparseTable(vector<int> &a){
    n = a.size();
    LOG = 32 - __builtin_clz(n); // floor(log2(n)) + 1

    st.assign(LOG, vector<int>(n));

    st[0] = a;

    for(int j = 1; j < LOG; j++){
      for(int i = 0; i + (1 << j ) <= n; i++){
        st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j - 1))]);
      }
    }
  }

  int query(int l,int r){
    int k = 31 - __builtin_clz(r - l + 1); // floor(log2(len))
    return min(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

int main(){
  fastio();

  int n;
  cin >> n;

  vector<int> a(n);
  for(auto &x : a) cin >> x;

  sparseTable st(a);

  int q;
  cin >> q;

  while(q--){ 
    int l,r;
    cin >> l >> r;

    cout << st.query(l,r) << endl;
  }

}
