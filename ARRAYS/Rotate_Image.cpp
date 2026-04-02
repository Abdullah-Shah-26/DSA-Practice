#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// (i, j) → (j, n-1-i)
//! TC = O(N^2)    SC = O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < m; j++){
        swap(mat[i][j],mat[j][i]);
      }
    }    

    for(int i = 0; i < n; i++){
      reverse(mat[i].begin(),mat[i].end());
    }
    }
};

//! Single Pass 

class Solution {
public:
  void rotate(vector<vector<int>>& a) {
  int n = a.size();

  /*
  r0   [i,j] - [i,j] # TOP
  r90        - [j, n - i - 1] # RIGHT
  r180       - [n - i - 1, n - j - 1] # BOTTOM
  r270       - [n - j - 1][i] # LEFT
  */

  for(int i = 0; i < n/2; i++){
    for(int j = i; j < n - i - 1; j++){
      int top = a[i][j];

      // top takes value from left
      a[i][j] = a[n-j-1][i];

      // left takes value from bottom
      a[n-j-1][i] = a[n-i-1][n-j-1];

      // bottom takes value from right
      a[n-i-1][n-j-1] = a[j][n-i-1];

      // right takes value from top [The value before we overwrote]
      a[j][n-i-1] = top;
    }
  }
  }
};