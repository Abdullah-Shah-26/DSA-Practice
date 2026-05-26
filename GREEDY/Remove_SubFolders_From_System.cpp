#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
  int n = folder.size();

  sort(folder.begin(), folder.end());

  vector<string> ans;
  string prev = folder[0];

  for(int i = 1; i < n; i++){
    if(folder[i].find(prev + "/") == 0){
      continue;
    }
    else{
      ans.push_back(prev);
      prev = folder[i];
    }
  }

  ans.push_back(prev);
  return ans;
  }
};