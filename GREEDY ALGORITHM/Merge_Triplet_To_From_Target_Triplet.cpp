#include <bits/stdc++.h>
using namespace std;

// A triplet is useless if it exceeds co-ordinate target

class Solution {
  public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
    vector<int> res(3, 0);

    for(auto &s : triplets){
      if(s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2])
        res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2])};
    }

    return res == t;
    }
};








