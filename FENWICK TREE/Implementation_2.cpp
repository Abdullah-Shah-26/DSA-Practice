#include <bits/stdc++.h>
using namespace std;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Fenwick Build in O(N) using Internal Tree Propogation

struct Fenwick{
  int n;
  vector<int> bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  //* O(N) build
  void build(vector<int> &a){
    for(int i = 1; i <= n; i++) bit[i] = a[i];

    for(int i = 1; i <= n; i++){
      int j = i + (i & -i);

      if(j <= n){
        bit[j] += bit[i];
      }
    }
  }


  //* add delta to idx -> i
  void update(int i,int delta){
    
    while(i <= n){
      bit[i] += delta;
      i = i + (i & -i);
    }
  }

  //* Prefix sum [1...i]
  int query(int i){
    int sum = 0;

    while(i > 0){
      sum += bit[i];
      i = i - (i & -i);
    }

    return sum;
  }


  //* Range Sum [l....r]
  int rangeQuery(int l, int r){
    return query(r) - query(l-1);
  }
};

int main(){
  fastio();

  int n;
  cin >> n;

  vector<int> a(n + 1,0);
  for(int i = 1; i <= n; i++) cin >> a[i];

  Fenwick ft(n); 
  ft.build(a); // O(N)

  int q;
  cin >> q;

  while(q--){
    int type;
    cin >> type;

    if(type == 1){
      int l,r;
      cin >> l >> r;
      cout << ft.rangeQuery(l,r) << endl;
    }
    else if(type == 2){
      int id, val;
      cin >>id >> val;

      /*
      Fenwick doesnt support set value directly so we first find diff b/w the old & new value 
      delta = newValue - oldValue 
      So we add the differance to old value to convert it to new Value
      */

      int delta = val - a[id]; 
      
      a[id]  = val; // updated new val in array
      ft.update(id, delta); // updated new val in Fenwick Tree
    }
  }

  
}