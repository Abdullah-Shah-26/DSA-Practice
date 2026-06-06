#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ans = "";
    void solve(string &curr,const int &n, const int &k, int &cnt){
     

      if(curr.size() == n){
          cnt++;
           
          if(cnt == k){
            ans = curr;
          }
          return;
      }


      for(char ch = 'a'; ch <= 'c'; ch++){
        if(!curr.empty() && curr.back() == ch){
          continue;
        }

        curr += ch;
        solve(curr, n, k, cnt);
        curr.pop_back();
      }
    }

    string getHappyString(int n, int k) {
    // TC = O(3 * 2^(N-1))
    // SC = O(N)

    string curr = "";
    int cnt = 0;
    solve(curr, n, k, cnt);    
    return ans;
    }
};