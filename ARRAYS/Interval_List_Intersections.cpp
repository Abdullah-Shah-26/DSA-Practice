#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N + M)
//! SC = O(1)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int>> ans;

    if(n == 0 || m == 0) return ans;

    int i = 0, j = 0;

    while(i < n && j < m){
      
      int st1 = A[i][0];
      int end1 = A[i][1];
      
      int st2 = B[j][0];
      int end2 = B[j][1];

      if(st2 <= end1 && st1 <= end2){
        ans.push_back({max(st1,st2), min(end1,end2)});
      }

      if(end1 < end2)
        i++;
      
      else
        j++;
      
    }

    return ans;    
    }
};
