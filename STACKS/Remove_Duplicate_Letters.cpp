#include <bits/stdc++.h>
using namespace std;

// Monotonic Stack 

class Solution {
public:
  string removeDuplicateLetters(string s) {
    int n = s.size();

    string ans = "";

    vector<bool> taken(26, false);
    vector<int> lastSeen(26);

    for(int i = 0; i < n; i++)
      lastSeen[s[i] - 'a'] = i;

    for(int i = 0; i < n; i++){
      int idx = s[i] - 'a';

      if(taken[idx])
        continue;

      while(ans.size() > 0 && ans.back() > s[i] && lastSeen[ans.back() - 'a'] > i){
        taken[ans.back() - 'a'] = false;
        ans.pop_back();
      } 

      taken[s[i] - 'a'] = true;
      ans += s[i];
    } 

    return ans;   
  }
};