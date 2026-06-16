#include <bits/stdc++.h>
using namespace std;

class DSU{
public:
  int maxActive; // Max active group size
  vector<int> parent, size;

  DSU(int n){
    maxActive = 1; 
    size.resize(n + 2, 1);
    parent.resize(n + 1, 0);
    iota(begin(parent), end(parent), 0);
  }

  int find(int x){
    return (x == parent[x]) ? x : parent[x] = find(parent[x]);
  }

  void unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(size[u] < size[v]) swap(u,v);

    parent[v] = u;
    size[u] += size[v];
    maxActive = max(maxActive, size[u]);
  }
};

class Solution {
public:
  int validSubarraySize(vector<int>& nums, int threshold) {
  int n = nums.size();

  DSU dsu(n);
  vector<pair<double, int>> valIdx; // {value, Idx}

  for(int i = 0; i < n; i++)
    valIdx.emplace_back(nums[i], i + 1); // Idx -> 1 based

  sort(begin(valIdx), end(valIdx));

  vector<bool> active(n + 1, false);

  int k = 1; // Min possible len 

  // Going largest -> smallest 
  for(int j = n-1; j >= 0 && k <= n;){
    double th = (double)threshold / k;

    while(j >= 0 && valIdx[j].first > th){
      
      int i = valIdx[j].second;
      active[i] = 1;
      
      if(i > 1 && active[i - 1])
        dsu.unite(i, i - 1);

      if(i < n && active[i + 1])
        dsu.unite(i, i + 1);

      j--;
    }

    // Need atleast one active element
    if(j < n-1 && dsu.maxActive >= k)
      return k;

    k++;
  }

  return -1;
  }
};