#include <bits/stdc++.h>
using namespace std;

// TC = O(M alpha(N) + NlogN)

class DSU {
public:
  vector<int> parent;
  vector<int> size;

  DSU(int n) {
    parent.resize(n + 1, 0);
    size.resize(n + 1, 1);
    iota(begin(parent), end(parent), 0);
  }

  int find(int x) { return (parent[x] == x) ? x : parent[x] = find(parent[x]); }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return false;

    if (size[u] < size[v])
      swap(u, v);

    parent[v] = u;
    size[u] += size[v];

    return true;
  }
};

class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums, vector<vector<int>> &swaps) {
    int n = nums.size();
    DSU dsu(n);

    // +nums[EvenIdx] - nums[OddIdx]

    for (auto it : swaps) {
      int u = it[0];
      int v = it[1];

      dsu.unite(u, v);
    }

    unordered_map<int, vector<int>> comp;

    for (int i = 0; i < n; i++) // [leader] -> {i1, i2 ....}
      comp[dsu.find(i)].push_back(i);

    long long ans = 0;
    for (auto &[root, indices] : comp) {

      vector<int> vals; // Values of this connected component
      int pos = 0, neg = 0;
      
      // Larger values are assigned to even indices --> +ans
      // Smaller values are assigned to odd indices  --> -ans

      for (int i : indices) {
        vals.push_back(nums[i]);

        if (i % 2 == 0)
          pos++;
        else
          neg++;
      }

      sort(begin(vals), end(vals));

      int j = 0;

      while (neg--) {
        ans -= vals[j];
        j++;
      }

      while (j < vals.size()) {
        ans += vals[j];
        j++;
        pos--;
      }
    }

    return ans;
  }
};