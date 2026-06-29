#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! 2D Difference Array Technique

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>>diff(n, vector<int>(n, 0));
    // TC = O(Q + N^2)
    // SC = O(1)
    
    for(auto &q : queries){
      int r1 = q[0];
      int c1 = q[1];
      int r2 = q[2];
      int c2 = q[3];

      diff[r1][c1] += 1; // Top Left
      if(c2 + 1 < n)
      diff[r1][c2 + 1] -= 1; // Top Right
      if(r2 + 1 < n)
      diff[r2 + 1][c1] -= 1; // Bottom Left
      if(r2 + 1 < n && c2 + 1 < n)
      diff[r2 + 1][c2 + 1] += 1; // Bottom Right
    }

    // 2D prefix sum
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        
          if(i > 0) diff[i][j] += diff[i-1][j];
          if(j > 0) diff[i][j] += diff[i][j-1];
          
          // Substract diagonal double cnt
          if(i > 0 && j > 0)
          diff[i][j] -= diff[i-1][j-1];
        }
      }

    return diff;
    }
};