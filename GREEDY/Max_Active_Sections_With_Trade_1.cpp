#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
  int n = s.size();
  int curZeroCnt = 0, prevZeroCnt = 0, alreadyOnes = 0, zeroSeg = 0, maxOnes = 0;
  
  for(int i = 0; i < n; i++){
    if(s[i] == '0') 
      curZeroCnt++;

    else{
      alreadyOnes++;
      maxOnes = max(maxOnes, curZeroCnt + prevZeroCnt);

      if(curZeroCnt > 0){
        prevZeroCnt = curZeroCnt;
        zeroSeg++;
      }

      curZeroCnt = 0; 
    }
  }

  if(curZeroCnt > 0) // Ended with zero segment
    zeroSeg++;

  maxOnes = max(maxOnes, curZeroCnt + prevZeroCnt);

  int total = 0;
  if(zeroSeg > 1)
    total = maxOnes + alreadyOnes;
  else
   total = alreadyOnes;
  
  return total;
  }
};