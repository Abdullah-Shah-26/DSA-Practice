#include <bits/stdc++.h>
using namespace std;

using ll = long long;
inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! O(N) Fenwick build using prefix sums to compute segment ranges directly

struct Fenwick{
  int n;
  vector<ll> bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  //* O(N) build using prefix sum
  void build(vector<ll> &a){

    vector<ll> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
      pref[i] = pref[i - 1] + a[i];
    }

    /*
    lowbit(i) = (i & -i) // Extracts the lowest set bit of i
    * [Size of segment handled by bit[i]]

    Query  : i -= lowbit(i)   -> Move to parent (Remove current block) 
    Update : i += lowbit(i)   -> Move to next container Node
    */

    for(int i = 1; i <= n; i++){
      int len = (i & -i);

      bit[i] = pref[i] - pref[i - len];
    }
  }

  //! Add Delta to idx -> i 
  void update(int i, ll delta){
    while(i <= n){
      bit[i] += delta;
      i = i + (i & -i);
    }
  }

  //! prefixSum [1....i]
  ll query(int i){
    ll sum = 0;
    while(i > 0){
      sum += bit[i];
      i = i - (i & -i);
    }

    return sum;
  }

  //! Range Sum [l...r]
  ll rangeQuery(int l,int r){
    return query(r) - query(l - 1);
  }

};