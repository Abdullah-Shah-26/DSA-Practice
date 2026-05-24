#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
  int n = s.size();

  int ans = 0;
  int freq[3] = {0,0,0};

  int l = 0;
  for(int r = 0; r < n; r++){
    freq[s[r] - 'a']++;

    while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
      ans += (n - r);

      freq[s[l] - 'a']--;
      l++;
    }
  }   

  return ans;
  }
};