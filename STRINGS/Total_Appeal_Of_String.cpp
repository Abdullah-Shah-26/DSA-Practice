#include <bits/stdc++.h>
using namespace std;

// Contribution Technique : 

class Solution {
public:
  long long appealSum(string s) {
  long long ans = 0;

  for(char ch = 'a'; ch <= 'z'; ch++){
    int lastIdx = -1; // Last idx where ch occurs

    for(int j = 0; j < s.size(); j++){
      if(s[j] == ch) 
        lastIdx = j;

    // Contribution of each character occurrence = number of substrings
    // ending at current index that contain that character.

      if(lastIdx != -1) 
        ans += (lastIdx + 1);
    }
  }

  return ans;
  }
};