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

// TC = O(N)
// SC = O(N)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.size();
    vector<long long>diff(n, 0);

    for(int i = 0; i < n; i++){
      int st = 0;
      int end = i;
      int shift = shifts[i];

      diff[st] += shift;
      if(end + 1 < n)
      diff[end + 1] -= shift;
    }
    // Cum Sum 
    for(int i = 1; i < n; i++){
      diff[i] += diff[i-1];
    }

    for(int i = 0; i < n; i++){
      int shift = diff[i] % 26;

      if(shift < 0){
        shift = (shift + 26) % 26;
      }

      int value = (s[i] - 'a');
      int updatedVal = (shift + value) % 26;
      s[i] = updatedVal + 'a';
    } 
    return s;
    }
};

//! Optimal
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.size();
    long long runningShift = 0;
    // TC = O(N)
    // SC = O(1)
    for(int i = n-1; i >= 0; i--){
      runningShift = (runningShift + shifts[i]) % 26;
      int value = s[i] - 'a';
      int updatedValue = (value + runningShift)%26;
      s[i] = 'a' + updatedValue;
    }
    return s;
    }
};