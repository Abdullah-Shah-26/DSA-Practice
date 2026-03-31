#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick2D{
  int n,m;
  vector<vector<ll>> bit;

  Fenwick2D(int n,int m) : n(n), m(m), bit(n + 1, vector<ll> (m + 1, 0)) {}
  
  void build(vector<vector<ll>> &a){ //! O(N * M)

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        bit[i][j] = a[i][j];
      }
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){

        int ni = i + (i & -i);
        int nj = j + (j & -j);

        if(ni <= n) bit[ni][j] += bit[i][j];
        if(nj <= m) bit[i][nj] += bit[i][j];

        //! Inclusion Exclusion - prevent double counting
        //! subtract overlap added twice via (ni,j) and (i,nj)
        if(ni <= n && nj <= m) bit[ni][nj] -= bit[i][j];
      }
    }
  }

  
  void update(int x, int y, ll delta){ //! O(LogN * LogM)
    for(int i = x; i <= n; i += (i & -i)){
      for(int j = y; j <= m; j += (j & -j)){
        bit[i][j] += delta;
      }
    }
  }

  ll query(int x,int y){ //! O(LogN * LogM)
    ll sum = 0; 

    for(int i = x; i > 0; i -= (i & -i)){
      for(int j = y; j > 0; j -= (j & -j)){
        sum += bit[i][j];
      }
    }

    return sum;
  }

  ll rangeQuery(int x1, int y1, int x2, int y2){ //! O(LogN * LogM)
    return query(x2,y2) - query(x1-1,y2) - query(x2, y1-1) + query(x1-1,y1-1);
  }

};

int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<ll>> a(n + 1, vector<ll> (m + 1,0));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }

  Fenwick2D ft(n,m);
  ft.build(a); //! O(N*M)

  int q;
  cin >> q;

  while(q--){
    int type;
    cin >> type;

    if(type == 1){
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      cout << ft.rangeQuery(x1,y1,x2,y2) << endl;
    }
    else{
      int x,y;
      ll value;

      cin >> x >> y >> value;

      ll delta = value - a[x][y];

      a[x][y] = value;
      ft.update(x, y, delta);
    }
  }
}
