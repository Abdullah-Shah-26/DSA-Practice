#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class Solution {
  public:
    string minWindow(string& s, string& t) {
    int n = s.size();
    int m = t.size();
    int stIdx = -1;
    int i = 0, minL = 1e9;
    
    while(i < n)
    {
        int j = 0;
        
        while(i < n){
            if(s[i]==t[j]) j++;
            if(j == m) break;
            i++;
        }
        if(i == n) break;
        int end = i;
        
        j = m - 1;
        while(j >= 0)
        {
            if(s[i] == t[j]) j--;
            i--;
        }
        int st = i + 1;
        
        int len = end - st + 1;
        if(len < minL)
        {
            minL = len;
            stIdx = st;
        }
        i = st + 1;
    }
    
    return stIdx == -1 ? "" : s.substr(stIdx,minL);
    }
};


