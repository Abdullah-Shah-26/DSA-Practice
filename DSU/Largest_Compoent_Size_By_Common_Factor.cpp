#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DSU + SPF
//* TC = A(Log(Log(A))) + N*LogA  where A = maxElement
//* SC = O(A + N)

class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

void buildSPF(vector<int> &spf, int maxi){
  for(int i = 1; i <= maxi; i++) spf[i] = i;

  for(int i = 2; i*i <= maxi; i++){ // TC = (maxi(Log(Log(maxi))))
    if(spf[i] == i){ // Prime No
      for(int j = i*i; j <= maxi; j += i){
        if(spf[j] == j){
          spf[j] = i; 
        }
      }
    }
  }
}

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
    int n = nums.size();
    int maxi = *max_element(begin(nums), end(nums));
    
    DSU dsu(n);
    
    vector<int> spf(maxi + 1);
    buildSPF(spf, maxi);

    vector<int> m(maxi + 1, -1); // Factor, Idx(Owner)

    auto process = [&](int factor, int i){
      if(m[factor] != -1){
        dsu.unite(m[factor], i);
      }
      else{
        m[factor] = i;
      }
    };

    for(int i = 0; i < n; i++){ // N*Log(maxi)
      int num = nums[i];

      while(num > 1){
        int factor = spf[num];

        process(factor, i);

        while(num % factor == 0){
          num /= factor;
        }
      }
    }

    int ans = 0;
    vector<int> cnt(n,0);

    for(int i = 0; i < n; i++){
      int p = dsu.find(i);

      cnt[p]++;

      ans = max(ans, cnt[p]);
    }

    return ans;
    }
};
