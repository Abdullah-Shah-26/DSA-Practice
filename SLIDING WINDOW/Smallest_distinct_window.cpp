#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findSubString(string& str) {
      vector<int>count(256,0);
      int first = 0;
      int second = 0; 
      int len = str.size();
      int diff = 0; // no of unique char in a string
              
          // calculate all the unique characters
      while(first < str.size())
      {
          if(count[str[first]] == 0)
          diff ++;
          
          count[str[first]] ++;
          first++;
      }
  // store total unique char and reset for sliding window 
      int required = diff;
      fill(count.begin(), count.end(), 0);
      first = 0; 
      second = 0;
      diff = required; // now diff represents no of unique char required
    // expand and contract the window to find the min len of substr
          while(second < str.size())
          {
              // diff 0 na ban jae tab tak
          // expand window untiil all unique char are included
              while(diff && second < str.size())
              {
                  if(count[str[second]] == 0)
                          diff-- ;// found a new unique char  
                  
                  count[str[second]]++;
                  second++;
              }
          if(diff == 0) // update min length
          len = min(len, second - first);
          
          
  // contract the window from left while its still valid
          while(diff == 0 && str.size())
          {
              
              len = min(len , second - first);
              count[str[first]]--;
              
              
              if(count[str[first]] == 0)
              diff++; // lost a unique char from the window
              
              first++;
          }
              
      }
          return len;
      
      }
  };
  