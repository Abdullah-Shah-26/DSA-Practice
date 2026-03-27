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
    //! TC = O(N Log N)
    //! SC = O(N)
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int,int>> vec;
    vector<vector<int>> ans;

    for(auto &b : buildings){
      int st = b[0];
      int end = b[1];
      int ht = b[2];

      vec.push_back({st, -ht});
      vec.push_back({end, ht});
    }    

    sort(begin(vec),end(vec));
 
    int curHt = 0;
    
    multiset<int> st;
    st.insert(0);

    for(auto &[x,ht] : vec){
      if(ht < 0){
        st.insert(-ht); // O(LogN)
      }
      else{
        st.erase(st.find(ht)); // O(LogN)
      }

      if(curHt != *st.rbegin()){
        ans.push_back({x, *st.rbegin()});
        curHt = *st.rbegin();
      }
    }

    return ans;
    }
};