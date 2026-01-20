#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class Solution {
public:
    int numberOfSubstrings(string s) {
    int lastSeen[3] = {-1,-1,-1};
    int cnt = 0;
    int n = s.size();
    for(int i = 0;i < n; i++)
    {
      lastSeen[s[i]-'a'] = i;
      
      cnt += (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
    }
    return cnt;
    }
};