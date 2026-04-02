#include <bits/stdc++.h>
using namespace std;

//! Fenwick + Co-ordinate Compression
//* TC = O(N Log N)
//* SC = O(N)

class Fenwick{
  public:
  int n;
  vector<int> bit;

  // Fenwick is storing the freq of prefix seen so far
  Fenwick(int N){
    n = N;
    bit.resize(n + 1, 0);
  } 

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
    int countRangeSum(vector<int>& nums, int L, int R) {
    int n = nums.size();

    vector<long long> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
      pref[i] = pref[i - 1] + nums[i - 1];
    }      

    // L <= pref[l] - pref[r - 1] <= R
    // L - pref[l] <= -pref[r - 1] <= R - pref[l]
    // pref[l] - L >= pref[r - 1] >= pref[l] - R
    // pref[l] - R <= pref[r - 1] <= pref[l] - L
    // Low <= prefSum <= High
    vector<long long> vals;
    for(int i = 0; i <= n; i++){
      vals.push_back(pref[i]);
      vals.push_back(pref[i] - L);
      vals.push_back(pref[i] - R);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();
    Fenwick ft(m);
    // Initally insert pref[0] = 0

    // Co-ordinate Compressed Idx from vals
    auto getId = [&](long long x){
      // +1 cause Fenwick is 1 based
      return lower_bound(begin(vals), end(vals), x) - vals.begin() + 1;
    };

    ft.update(getId(0),1);
    long long ans = 0;

    for(int j = 1; j <= n; j++){
      long long cur = pref[j];

      long long low = cur - R;
      long long high = cur - L;
 
      int l = lower_bound(vals.begin(), vals.end(), low) - vals.begin();
      int r = upper_bound(vals.begin(), vals.end(), high) - vals.begin();

      ans += ft.query(r) - ft.query(l);

      ft.update(getId(cur), 1); 
    }

    return ans;
    }
};
