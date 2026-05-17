#include <bits/stdc++.h>
using namespace std;

// N = A + B + C
// TC = O(N) | SC = O(Log(3)) - Heap size is always 3

class Solution {
  public:
    string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> pq;

    if(a > 0) pq.push({a, 'a'});
    if(b > 0) pq.push({b, 'b'});
    if(c > 0) pq.push({c, 'c'});

    string ans = "";

    while(!pq.empty()){
      auto [f1, ch1] = pq.top(); pq.pop();

      if(ans.size() >= 2 && ans[ans.size() - 1] == ch1 && ans[ans.size() - 2] == ch1){
        // Can't use curChar check for next largest char
        if(pq.empty()){
          break;
        }
        auto [f2, ch2] = pq.top(); pq.pop();
    
        ans += ch2; 
        f2--;

        if(f2 > 0){
          pq.push({f2, ch2});
        }
      }

      ans += ch1;
      f1--;

      if(f1 > 0) pq.push({f1, ch1});
    }

    return ans;
    }
};