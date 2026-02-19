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

class Solution {
  public:
    // TC = O(N)
    // SC = O(N)
    void computeLPS(string pat, vector<int>& LPS){
        int len = 0;
        int i = 1;
        LPS[0] = 0;
        
        while(i < pat.size()){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len > 0){
                len = LPS[len- 1];
                }
                else{
                LPS[i]= 0;
                i++;
                }
            }
        }
    }
  
    int minChar(string &s) {
    string rev = s;
    reverse(begin(rev), end(rev));
    string temp = s + "-" + rev;
    
    vector<int>LPS(temp.size());
    computeLPS(temp, LPS);
    
    int longestLPSLen = LPS[temp.size() - 1];
    
    string culprint = rev.substr(0, s.size() - longestLPSLen);
    
    return culprint.size();
    }
};
