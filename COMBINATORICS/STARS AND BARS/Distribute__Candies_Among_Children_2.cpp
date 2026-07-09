#include <bits/stdc++.h>
using namespace std;

// Recursion + Backtracking
// TC = O(Limit ^ 3) since we have 3 children 

using ll = long long;

class Solution {
public:
  ll f(int childCnt, int n, int limit){
    if(childCnt == 3){
      if(n == 0)
        return 1;
      return 0;
    }

    ll ways = 0;
    for(int assigned = 0; assigned <= min(limit, n); assigned++){
      ways += f(childCnt + 1, n - assigned, limit);
    }

    return ways;
  }

  long long distributeCandies(int n, int limit) {
    return f(0, n, limit);
  }
};


// TC = O(N^3)

class Solution {
public:

  long long distributeCandies(int n, int limit) {
    ll ways = 0;
    
    for(int c1 = 0; c1 <= min(n, limit); c1++)
      for(int c2 = 0; c2 <= min(n - c1, limit); c2++)
        for(int c3 = 0; c3 <= min(n - c1 - c2, limit); c3++)
          if(c1 + c2 + c3 == n)
            ways++;

    return ways;
  }
};