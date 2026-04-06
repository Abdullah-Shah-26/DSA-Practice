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
  //! TC = O(N + M)
  //! SC = O(M)
  void computeLPS(string &pat, vector<int>&LPS, int M){
        int len = 0;
        
        LPS[0] = 0;
        
        int i = 1;
        
        while(i < M){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
              if(len != 0)
                len = LPS[len - 1];
              else{
                  LPS[i] = 0;
                  i++;
              }
            }
        }
    }
  
    vector<int> search(string &pat, string &txt) {
    int N = txt.size();
    int M = pat.size();
    vector<int>LPS(M,0);
    computeLPS(pat, LPS, M);
    // Create an LPS array to store the length of longest 
    // Common Prefix - Suffix
    // LPS[i] = longest Proper Prefix pat[0.....i]
    // Which is also Suffix of [0......i]
    vector<int>res;
    int i = 0;
    int j = 0;
    while(i < N){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == M){
            res.push_back(i - M); // Idx of Pattern
            j = LPS[j-1];
        }
        else if(txt[i] != pat[j]){
            if(j > 0){
                j = LPS[j-1];
            }
            else{
                i++;
            }
        }
    }
    return res;
    }
};