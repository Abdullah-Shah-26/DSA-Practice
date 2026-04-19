#include <bits/stdc++.h>
using namespace std;

const int INF =1e9;

//* Visit each node exactly once & return back to start

//* TC = O(N * 2^N) * N [Work per state]
//* SC = O(N * 2^N)

// Adj Matrix
int n = 4;
int dist[10][10] = {
  {0,20,42,25},
  {20,0,30,34},
  {42,30,0,10},
  {25,34,10,0},
};

int dp[1 << 4][4];

int visitedAll = (1 << n) - 1;

int tsp(int mask, int u){
  if(mask == visitedAll) return dist[u][0]; // back to start

  if(dp[mask][u] != -1)
    return dp[mask][u];

  int ans = INF;  
  for(int v = 0; v < n; v++){
    if(!(mask & (1 << v))){
      int newAns = dist[u][v] + tsp(mask | (1 << v), v);
      ans = min(newAns, ans);
    }
  }

  return dp[mask][u] = ans;
}

int main(){
  memset(dp,-1, sizeof(dp));
  cout << tsp(1, 0) << endl;
}