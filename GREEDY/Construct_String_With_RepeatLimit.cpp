#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(1)
// 2 Pointer + FreqMap
// Greedily using lexicographically largest char

class Solution {
public:
  string repeatLimitedString(string s, int repeatLimit) {
  vector<int> count(26, 0);

  for(char &ch : s){
    count[ch - 'a']++;
  }    

  string ans;

  int i = 25;
  while(i >= 0){
    if(count[i] == 0){
      i--;
      continue;
    }

    char ch = i + 'a';
    int freq = min(count[i], repeatLimit);

    ans.append(freq, ch);
    count[i] -= freq;

    if(count[i] > 0){ // Break streak of I-th char
      int j = i - 1;
      while(j >= 0 && count[j] == 0){
        j--;
      }

      if(j < 0){
        break;
      }

      ans += (j + 'a');
      count[j]--;
    }
  }

  return ans;
  }
};