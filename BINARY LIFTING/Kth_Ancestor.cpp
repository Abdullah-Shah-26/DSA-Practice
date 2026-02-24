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

class TreeAncestor {
public:
    //      build      +  Q queries
    // TC = O(N Log N) + O(Q Log N)
    // SC = O(N Log N)

    static const int MAX = 20;
    vector<vector<int>> ancestor;
    TreeAncestor(int n, vector<int>& parent) {
      ancestor.assign(n, vector<int>(MAX, -1));

      // 2^0 = Immediate Parent
      for(int node = 0; node < n; node++){
        ancestor[node][0] = parent[node];
      }

      // Building Binary Lifting Table
      for(int pow = 1; pow < MAX; pow++){
        for(int node = 0; node < n; node++){
          int midAncestor = ancestor[node][pow - 1];

          if(midAncestor != -1){
            ancestor[node][pow] = ancestor[midAncestor][pow - 1]; 
          }
        }
      }
    }
    
    int getKthAncestor(int node, int k) {
        for(int pow = 0; k && node != -1; pow++){
          if(k & 1){ // Loop Until K != 0
            node = ancestor[node][pow];
          }
          k >>= 1; // k /= 2 // Keeps removing last bit
        }    
       return node;
    }
};
