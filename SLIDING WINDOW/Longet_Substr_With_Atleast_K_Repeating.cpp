#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Divide & Conquer
//! TC = O(N^2) - Worst Case 
//! SC = O(N) recurison

class Solution {
public:
    int f(string &s, int st, int end, const int &k){
      if(end - st < k) return 0;

      int freq[26];
      memset(freq, 0, sizeof(freq));

      for(int i = st; i < end; i++) freq[s[i]-'a']++;

      for(int i = st; i < end; i++){
        // Invalid Char - Break 
        if(freq[s[i] - 'a'] < k){
          int j = i;

          while(j < end && freq[s[j]- 'a'] < k) j++;

          return max(f(s,st,i,k),f(s,j,end,k));
        }
      }

      return end - st;
    }

    int longestSubstring(string s, int k) {
    return f(s, 0, s.size(), k);    
    }
};

 //! Sliding Window 
 //! TC = (26 * N)
 //! SC = O(1)
class Solution {
  public:  
    int longestSubstring(string s, int k) {
    int n = s.size();
    int maxLen = 0;
    
    for(int targetUnique = 1; targetUnique <= 26; targetUnique++){
      int l = 0, r = 0;
      int unique = 0, cntAtLeastK = 0;
      int freq[26];
      memset(freq, 0, sizeof(freq));

      // Expand
      while(r < n){
        char ch = s[r];

        if(freq[ch-'a'] == 0) unique++;
        freq[ch-'a']++;

        if(freq[ch-'a'] == k) cntAtLeastK++;

        r++;

        // Shrink
        while(unique > targetUnique){
          char leftCh = s[l];

          if(freq[leftCh - 'a'] == k) cntAtLeastK--;

          freq[leftCh - 'a']--;

          if(freq[leftCh - 'a'] == 0) unique--;

          l++;
        }

        /// Validity condition check
        if(unique == targetUnique && cntAtLeastK == targetUnique){
          maxLen = max(maxLen, r - l);
        }
      }
    }

    return maxLen;    
    }
};