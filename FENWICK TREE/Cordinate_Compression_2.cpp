#include <bits/stdc++.h>
using namespace std;

using ll = long long;
inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! FenWick Tree + Co - ordinate Compression

struct Fenwick{
  int n;
  vector<int> bit; //! Behaves as Dynamic Histogram in here

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  void update(int i,int delta){
    while(i <= n){
      bit[i] += delta;
      i = i + (i & -i);
    }
  }

  int query(int i){
    int sum = 0;
    
    while(i > 0){
      sum  += bit[i];
      i = i - (i & -i);
    }

    return sum;
  }
};

int main(){
  fastio();

  // int n;
  // cin >> n;

  // vector<int> a(n);
  // for(int i = 0; i < n; i++) cin >> a[i];

  int n = 5;
  vector<int> a = {8,3,10,3,6};

  //! 1. Cordinate Compression using binary search
  vector<int> vals = a;
  sort(begin(vals), end(vals));
  vals.erase(unique(begin(vals), end(vals)), vals.end());

  // 2. Fenwick
  Fenwick ft(vals.size());

  for(int i = 0; i < n; i++){
    int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;

    int smallerGuys = ft.query(id - 1); // strictly smaller

    cout << "a[" << i << "] = " << a[i] << " smaller before this :  " << smallerGuys << endl;
    
    ft.update(id, 1);
  }

}