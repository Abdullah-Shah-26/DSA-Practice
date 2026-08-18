#include <bits/stdc++.h>
using namespace std;

// Slightly Implementation Heavy :

class Solution {
public:
  bool isValid(string &s){
    if(s.empty())
      return false;

    for(char &ch : s)
      if(!isalnum(ch) && ch != '_')
        return false;

    return true;
  }

  vector<string> validateCoupons(vector<string>& c, vector<string>& b, vector<bool>& isActive) {
    int n = c.size();
    
    unordered_map<string,int> m = {
      {"electronics", 0},{"grocery", 1},{"pharmacy", 2},{"restaurant", 3}
    };

    vector<pair<int, string>> temp;

    for(int i = 0; i < n; i++)
      if(isActive[i] && m.count(b[i]) && isValid(c[i]))
        temp.push_back({m[b[i]], c[i]});

    sort(begin(temp), end(temp));

    vector<string> ans;

    for(auto &[_, s] : temp)
      ans.push_back(s);

    return ans;
  }
}; 