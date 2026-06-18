#include <bits/stdc++.h>
using namespace std;

// TC = O(N) 

class Solution {
public:
  char processStr(string s, long long k) {
  int n = s.size();
  long long L = 0;

  // Processing string from L -> R 
  for(char &ch : s){
    if(ch == '*'){ // Deletes char 
      if(L > 0)
        L--;
    }
    else if(ch == '#'){ // Doubles result
      L *= 2;
    }
    else if(ch == '%'){ // Reverses result, no change in Len
      continue;
    }
    else{ // Process i.e adds char
      // a-z 
      L++;
    }
  }

  if(k >= L){
    return '.';
  }

  // Reverse process string from R -> L
  for(int i = n-1; i >= 0; i--){
    if(s[i] == '*'){ // Before this char was deleted so we must have larger len
      L++; 
    }
    else if(s[i] == '#'){
      L /= 2;
      
      if(k >= L)
        k -= L;
    }
    else if(s[i] == '%'){
      k = L - k - 1;
    }
    else{ // Normal char 
      L--;
    }

    if(k == L)
      return s[i];
  }

  return '.';
  }
};