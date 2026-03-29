#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(2*N)
//! SC = O(1)

class Solution {
public:
    vector<int> partitionLabels(string s) {
    int n = s.size();
    int last[26]; // LastSeen at this idx
    memset(last, -1, sizeof(last));   

    for(int i = 0; i < n; i++){
      last[s[i]-'a'] = i;
    }

    vector<int> ans;

    int i = 0;

    while(i < n){
      int end = last[s[i] - 'a'];

      int j = i;
      while(j < end){
        end = max(end, last[s[j] - 'a']);
        j++;
      }

      ans.push_back(j - i + 1);
      i = j + 1; 
    }

    return ans;
    }
};

//! TC = O(N)
//! SC = O(1)

class Solution {
public:
    vector<int> partitionLabels(string s) {
    int n = s.size();
    int last[26];
    memset(last, -1, sizeof(last));

    for(int i = 0; i  < n; i++) last[s[i]-'a'] = i;

    vector<int> ans;

    int i = 0;
    int st = 0;
    int end = 0; 
    
    while(i < n){
      end = max(end, last[s[i] - 'a']); 
      
      if(i == end){
        ans.push_back(end - st + 1);
        st = i + 1;
      }

      i++;
    }

    return ans;   
    }
};