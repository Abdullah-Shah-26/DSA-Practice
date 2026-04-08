#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
using pii = pair<int,int>; // {dist, node}

vector<int> shortestPath(int V, int m, vector<vector<int>> &edges) {

    // Build adjacency list
    vector<vector<pair<int,int>>> adj(V + 1);
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //! Dijkstra setup
    vector<int> dist(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);
    vector<bool> visited(V + 1, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (!visited[v] && d + w < dist[v]) {
                dist[v] = d + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // If unreachable
    if (dist[V] == INT_MAX) return {-1};

    // Reconstruct path
    vector<int> path;
    int cur = V;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());
    path.push_back(dist[V]); // append total cost

    return path;
}
};