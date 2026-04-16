#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Patience Sorting + Custom Sorting 
class Solution {
public:
   static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0])
        return a[0] < b[0];   // first element ascending

    return a[1] > b[1];       // second element descending
}

    int maxEnvelopes(vector<vector<int>>& e) {
    sort(e.begin(),e.end(),cmp); 
    // LIS Using Patience Sorting
    vector<int> sorted;
    int n = e.size();

    for(int i = 0; i < n; i++){
      auto it = lower_bound(sorted.begin(),sorted.end(), e[i][1]);
      if(it == sorted.end()){
        sorted.push_back(e[i][1]);
      } else{
        *it = e[i][1];
      }
    }
    return (int)sorted.size();
    }
};