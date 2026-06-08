#include <bits/stdc++.h>
using namespace std;

// Brute Force : 

class Solution {
public:
  int n,m;
  int ans;
  int dp[101];
  vector<vector<int>> grid;

  void f(int i, int score){
    if(i >= n)
      return;

    // skip
    f(i + 1, score);

    // take
    for(int j = 0; j < m; j++){
      int val = grid[i][j];
      if(dp[val] == 0){
        dp[val]++; // do 
        ans = max(ans, score + val);
        f(i + 1, score + val); // explore
        dp[val]--; // undo
      }
    }
  }

  int maxScore(vector<vector<int>>& grid) {
    this->grid = grid;
    n = grid.size();
    m = grid[0].size();

    ans = 0;
    memset(dp, 0, sizeof(dp));
    f(0, 0);

    return ans;
  }
};

// Rec + Memo - BitMask DP 
// TC = O(Unique vals * 2^R * R)
// SC = O(Unique vals * 2^R)

class Solution {
public:
  int n,m;
  int ans;
  vector<int> arr;
  vector<vector<int>> grid;
  map<int, vector<int>> mp;
  vector<vector<int>> dp;

  int f(int i, int mask){
    if(i == arr.size())
      return 0;

    if(dp[i][mask] != -1)
      return dp[i][mask];

    int ans = f(i + 1, mask); // Skip

    for(auto row : mp[arr[i]])
      if(!(mask & (1 << row))) // Take
        ans = max(ans, arr[i] + f(i + 1, (mask | (1 << row))));

    return dp[i][mask] = ans;
  }

  int maxScore(vector<vector<int>>& grid) {
    this->grid = grid;
    n = grid.size();
    m = grid[0].size();

    set<int> st;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)  
        st.insert(grid[i][j]);

    for(auto &i : st)
      arr.push_back(i);

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        mp[grid[i][j]].push_back(i); // mp[value] - {In which rows it occured}

    dp.assign(arr.size(), vector<int> (1 << n, -1));
    return f(0, 0);
  }
};

// Iterative 

class Solution {
public:
  int maxScore(vector<vector<int>>& grid) {
    int n = grid.size();

    unordered_map<int, vector<int>> mp;
    set<int> st;

    for(int r = 0; r < n; r++)
      for(int x: grid[r]){
        st.insert(x);
        mp[x].push_back(r);
      }

    vector<int> arr(begin(st), end(st));
    int U = arr.size();

    vector<vector<int>> dp(
      U + 1,
      vector<int>(1 << n, 0)
    );

    for(int i = U - 1; i >= 0; i--) {
      int val = arr[i];

      for(int mask = 0; mask < (1 << n); mask++) {

        // Skip
        dp[i][mask] =
          dp[i + 1][mask];

        // Take
        for(int row : mp[val]) {

          if(mask & (1 << row))
            continue;

          int newMask = mask | (1 << row);
          dp[i][mask] = max(dp[i][mask], val + dp[i + 1][newMask]);
        }
      }
    }

    return dp[0][0];
  }
};