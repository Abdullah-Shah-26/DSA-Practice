#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        // BFS (Covid) - spreads to those which are in direct contact
        // TC = O(V + E)
        // SC = O(V + V)
        // Steps
        // 1 . pop the node from Q & put iin ans
        // 2 . Node will look into its unvisited neighbour
        // 3 . push them in q and mark visited as 1
        int V = adj.size();
        queue<int> q;
        q.push(0);
        vector<bool> visited(V, 0);
        visited[0] = 1;

        vector<int> ans;
        int node;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++)
            {
                // If node is unvisited - mark as visited and put in q
                if (!visited[adj[node][j]])
                {
                    visited[adj[node][j]] = 1;
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};