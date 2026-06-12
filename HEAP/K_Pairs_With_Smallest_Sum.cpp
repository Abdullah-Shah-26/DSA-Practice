#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(K * Log( min(M*N, K)))

class Solution {
public:
  typedef tuple <int,int,int> T;
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  int n = nums1.size();
  int m = nums2.size();

  priority_queue<T, vector<T>, greater<T>> pq;
  vector<vector<int>> ans;
  set<pair<int,int>> vis;

  pq.push({nums1[0] + nums2[0], 0, 0});
  vis.insert({0, 0});

  while(k-- && !pq.empty()){
    auto [sum, i, j] = pq.top();
    pq.pop();

    ans.push_back({nums1[i], nums2[j]});

    if(i + 1 < n && !vis.count({i + 1, j})){
      vis.insert({i + 1, j});
      pq.push({nums1[i + 1] + nums2[j], i + 1, j});
    }

    if(j + 1 < m && !vis.count({i, j + 1})){
      vis.insert({i, j + 1});
      pq.push({nums1[i] + nums2[j + 1], i, j + 1});
    }
  }

  return ans;
  }
};