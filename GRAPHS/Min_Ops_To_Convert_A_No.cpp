#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS 
class Solution {
public:
    int minimumOperations(vector<int>& nums, int x, int y) {
    vector<bool> vis(1001,0);
    queue<int> q;

    q.push(x);
    vis[x] = 1;
    
    int steps = 0;

    while(!q.empty()){
      int size = q.size();

      while(size--){
        int x = q.front();
        q.pop();

        // if(x == y) return steps;

        for(auto &num: nums){
          int a = x + num;
          int b = x - num;
          int c = x ^ num;

        // ans can we valid but never pushed in q cause of constraint 0-1000 so check here 
        if(a == y || b == y || c == y) return steps+1;

        if(0 <= a && a <= 1000 && !vis[a]) {
          vis[a] = 1;
          q.push(a);
        }

        if(0 <= b && b <= 1000 && !vis[b]) {
            vis[b] = 1;
            q.push(b);
        }

        if(0 <= c && c <= 1000 && !vis[c]) {
            vis[c] = 1;
            q.push(c);
        }
        }
    }
      steps++;
    }

    return -1;
    }
};