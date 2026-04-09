#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS - Level Order 
//* TC = O(V + E) = O(Limit)
//* SC = O(Limit)

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
    if(x <= y) return y - x;

    int limit = max(x,y) + 10; // To make it divisible by 5/11 max +10
    
    vector<bool> vis(limit + 1, 0);
    queue<int> q;
    
    q.push(x);
    vis[x] = 1;

    int steps = 0;

    while(!q.empty()){
      int size = q.size();

      while(size--){
        int n = q.front();
        q.pop();

        if(n == y) return steps;

        if(n%11 == 0){
          int next = n/11;

          if(!vis[next]){
            vis[next] = 1;

            q.push(next);
          }
        }

        if(n%5 == 0){
          int next = n/5;

          if(!vis[next]){
            vis[next] = 1;

            q.push(next);
          }
        }

        if(n-1 >= 0 && !vis[n-1]){
          vis[n-1] = 1;

          q.push(n-1);
        }

        if(n+1 <= limit && !vis[n+1]){
          vis[n+1] = 1;

          q.push(n + 1);
        }
      }

      steps++;
    }

    return steps;
    }
};