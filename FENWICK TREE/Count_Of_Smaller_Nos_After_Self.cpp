#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log N)
//! SC = O(N)

struct Fenwick{
  int n;
  vector<int> bit;

  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  void update(int i, int delta){
    while(i <= n){
      bit[i] += delta;
      i = i + (i & -i);
    }
  }

  int query(int i){
    int sum = 0;
    while(i > 0){
      sum += bit[i];
      i = i - (i & -i);
    }
    return sum;
  }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      int n = nums.size();
      vector<int> vals = nums;
      sort(vals.begin(), vals.end());
      vals.erase(unique(begin(vals), end(vals)), vals.end());
      vector<int> ans(n);

      Fenwick ft(vals.size());

      for(int i = n-1; i >= 0; i--){
        int id = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin() + 1;

        // Cnt of guys strictly smaller & towards left
        int cnt =  ft.query(id - 1);

        ans[i] = cnt;

        ft.update(id, 1);
      }
  
      return ans;
    }
};  