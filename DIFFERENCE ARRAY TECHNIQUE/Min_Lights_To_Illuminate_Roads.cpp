#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minLights(vector<int>& lights) {
  int n = lights.size();

  vector<int> diff(n); // illuminated

  for(int i = 0; i < n; i++){
    int x = lights[i];

    if(x == 0) 
      continue;

    int l = max(i - x, 0);
    int r = min(n - 1, i + x);

    diff[l]++;
    if(r + 1 < n) diff[r + 1]--;
  }    

  for(int i = 1; i < n; i++)
    diff[i] += diff[i - 1];

  int ans = 0;

  for(int i = 0; i < n; ){
    if(diff[i] > 0){
      i++;
      continue;
    }

   // Find segment of zeros
    int j = i;
    while(j < n && diff[j] == 0) 
      j++;

    int len = j - i;
    ans += (len + 3 - 1)/3; // ceil(len/3)

    i = j;
  }

  return ans;
  }
};