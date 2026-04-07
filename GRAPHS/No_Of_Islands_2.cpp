#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(Q * Alpha(N*M))  || SC = O(N*M)

class DSU {
  public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return (x == parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int row[4] = {0,0,-1,1};
int col[4] = {1,-1,0,0};

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &query){
    DSU dsu(n*m);

    vector<vector<bool>> vis(n, vector<bool>(m,0)); 

    int cnt = 0;
    vector<int> ans;

    for(auto &q: query){
        int r = q[0];
        int c = q[1];

        if(vis[r][c] == 1){ // Already Visited
            ans.push_back(cnt);
            continue;
        } 

        vis[r][c] = 1;
        cnt++;

        for(int k = 0; k < 4; k++){
            int nr = r + row[k];
            int nc = c + col[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc]){ // vis[nr][nc] == 1 means adj guy is island, unite
               int node = r*m + c;
               int adjNode = nr * m + nc;

               if(dsu.find(node) != dsu.find(adjNode)){
                   cnt--;
                   dsu.unite(node, adjNode);
               }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}