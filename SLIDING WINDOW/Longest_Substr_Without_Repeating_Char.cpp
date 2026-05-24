#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
  int n = s.size();
  int maxLen = 0;

  unordered_map<char,int> m;

  int l = 0;
  for(int r = 0; r < n; r++){
    m[s[r]]++;

    while(m[s[r]] > 1){
      m[s[l]]--;
      l++;
    }

    maxLen = max(maxLen, r - l + 1);
  } 

  return maxLen;
  }
};

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
  int n = s.size();
  int maxLen = 0;

  int seen[256];
  memset(seen, -1, sizeof(seen));

  int l = 0;
  for(int r = 0; r < n; r++){
    char ch = s[r];

    if(seen[ch] != -1){
      if(seen[ch] >= l){
        l = seen[ch] + 1;
      }
    }
    
    seen[ch] = r;
    maxLen = max(maxLen, r - l + 1);
  } 

  return maxLen;
  }
};