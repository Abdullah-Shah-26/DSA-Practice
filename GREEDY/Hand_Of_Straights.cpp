#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN) | SC = O(N)

class Solution {
public:
  bool isNStraightHand(vector<int>& arr, int k) {
  int n = arr.size();

  if(n % k != 0) return false;

  map<int,int> m;
  for(int &x : arr){
    m[x]++;
  }    

  while(!m.empty()){
    int cur = m.begin()->first;

    for(int i = 0; i < k; i++){
      if(!m.count(cur + i)){
        return false;
      }

      m[cur + i]--;
      if(m[cur + i] == 0) m.erase(cur + i); 
    }
  }

  return true;
  }
};