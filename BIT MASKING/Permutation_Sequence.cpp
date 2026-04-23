#include <bits/stdc++.h>
using namespace std;

// TC = O(N! * N) = no of perms * work done per perm
// SC = O(N) = recursion stack depth

class Solution {
  public:
    string ans;
    int cnt, k, n;

    void solve(int mask, string &perm){

      // Prune - Kill already entered calls if ans found   
      if(ans != "")
        return;
      
      if(perm.size() == n){
        cnt++;
        if(cnt == k){
          ans = perm;
        }
        return;
      }

      for(int i = 1; i <= n; i++){
        if(mask & (1 << i)) continue;

        perm += to_string(i);

        if(ans != "") // Prevent unnecessary new recursion calls 
          return; 

        solve(mask | (1 << i), perm);
        perm.pop_back();
      }
    }

    string getPermutation(int N, int K) {
    int mask = 0;
    cnt = 0, n = N, k = K;
    ans = "";
    string perm = "";

    solve(mask, perm);

    return ans;   
    }
};