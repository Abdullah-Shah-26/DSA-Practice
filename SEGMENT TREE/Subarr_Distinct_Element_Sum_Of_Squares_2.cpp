#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN) | SC = O(N)

using ll = long long;
const int MOD = 1e9 + 7;

struct SegTree{
  int n;
  vector<ll> lazy;
  vector<ll> sum;
  vector<ll> square;

  SegTree(int size){
    n = size;

    lazy.resize(4*n, 0);
    sum.resize(4*n, 0);
    square.resize(4*n, 0);
  }

  // Apply pending lazy updates
  void push(int i, int l, int r){
    if(lazy[i] == 0) 
      return;

    ll add = lazy[i];
    ll len = r - l + 1;

    // (x + add)^2 = (Old Square Sum)x^2 + 2*(sum of all x)*add + add^2 (To all x)
    square[i] = (square[i] + 2LL * add * sum[i] + add*add*len) % MOD;

    sum[i] = (sum[i] + add * len) % MOD;

    if(l != r){
      lazy[2 * i + 1] += add;
      lazy[2 * i + 2] += add;
    }

    lazy[i] = 0;
  }

  void rangeAdd(int i, int l, int r, int ql, int qr){
    push(i, l, r);

    if(r < ql || l > qr)
      return;

    if(l >= ql && r <= qr){
      lazy[i] += 1;
      push(i, l, r);
      return;
    }

    int mid = (l + r) >> 1;

    rangeAdd(2*i + 1, l, mid, ql, qr);
    rangeAdd(2*i + 2, mid + 1, r, ql, qr);

    sum[i] = (sum[2*i + 1] + sum[2*i + 2]) % MOD;

    square[i] = (square[2*i + 1] + square[2*i + 2]) % MOD;
  }

  void rangeAdd(int l, int r){
    rangeAdd(0, 0, n-1, l, r);
  }
};

class Solution {
public:
  int sumCounts(vector<int>& nums) {
  int n = nums.size();

  SegTree seg(n);

  unordered_map<int,int> lastSeen;

  ll ans = 0;

  for(int j = 0; j < n; j++){
    int prev = -1;

    if(lastSeen.count(nums[j]))
      prev = lastSeen[nums[j]];

    // all subarrays starting here 
    // gain +1 distinct
    int left = prev + 1;
    int right = j;

    seg.rangeAdd(left, right);

    ans = (ans + seg.square[0]) % MOD;

    lastSeen[nums[j]] = j;
  }

  return ans;   
  }
};