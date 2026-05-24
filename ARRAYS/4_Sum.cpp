#include <bits/stdc++.h>
using namespace std;

// TC = O(N^3)

using ll = long long;
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& a, int target) {
  int n = a.size();
  
  sort(begin(a), end(a));
  
  vector<vector<int>> ans;

   for(int i = 0; i < n; i++){

    // Skip duplicate i
    if(i > 0 && a[i] == a[i - 1])
      continue;

    for(int j = i + 1; j < n; j++){
      
      // Skip duplicate j
      if(j > i + 1 && a[j] == a[j - 1])
        continue;

      int k = j + 1;
      int l = n - 1;

      while(k < l){
        ll sum = a[i];
        sum += a[j];
        sum += a[k];
        sum += a[l];

        if(sum == target){
          ans.push_back({a[i], a[j], a[k], a[l]});

          k++;
          l--;

          while(k < l && a[k] == a[k - 1])
            k++;

          while(k < l && a[l] == a[l + 1])
            l--;
        }
        else if(sum < target)k++;
        else l--;
      }
    }
  }

  return ans;
  }
};