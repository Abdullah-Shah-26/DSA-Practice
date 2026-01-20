#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &s)
{
         int maxl = -1, r = 0, l = 0, n = s.size();
      unordered_map<char,int>m;
      while(r < n)
      {
          m[s[r]]++;
          if(m.size() > k)
          {
              m[s[l]]--;
              if(m[s[l]] == 0)
              m.erase(s[l]);
              l++;
          }
          maxl = max(maxl, r - l + 1);
          r++;
      }
      return maxl;
}