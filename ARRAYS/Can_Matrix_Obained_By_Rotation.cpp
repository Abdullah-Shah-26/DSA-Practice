#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
    bool r0 = 1, r90 = 1, r180 = 1, r270 = 1;

    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(mat[i][j] != tar[i][j]) r0 = 0;
        if(mat[i][j] != tar[j][n-i-1]) r90 = 0;
        if(mat[i][j] != tar[n-i-1][n-j-1]) r180 = 0;
        if(mat[i][j] != tar[n-j-1][i]) r270 = 0;  
      }
    }

    return r0 || r90 || r180 || r270;    
    }
};