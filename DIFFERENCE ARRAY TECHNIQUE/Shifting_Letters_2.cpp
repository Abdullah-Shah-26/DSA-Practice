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

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int>diff(n,0);
  // TC = O(Q + N)
  // SC = O(N)
    for(auto &s : shifts){
      int st = s[0];
      int end = s[1];
      int shift = (s[2] == 0) ? -1 : 1;

      diff[st] += shift;
      if(end + 1 < n)
      diff[end + 1] -= shift;
    }     
    // Find Cum Sum
    for(int i = 1; i < n; i++){
      diff[i] += diff[i-1];
    } 

    for(int i = 0; i < n; i++){
    // Corner Case
    // Wrap Around
      int shift = diff[i] % 26;
      
      if(shift < 0){
        shift += 26;
      }
      
      int value = (s[i] - 'a');
      int updatedValue = (value + shift)%26;
      s[i] = updatedValue + 'a';
    }
    return s;
    }
};