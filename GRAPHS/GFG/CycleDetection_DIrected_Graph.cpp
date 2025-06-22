#include <bits/stdc++.h>
class Solution
{
public:
    //! CYCLE DETECTION - DIRECTED GRAPH
    bool DetectCycle(int node, const vector<vector<int>> &adj, vector<int> &path, vector<int> &visited)
    {
        //! DFS
        visited[node] = 1;
        path[node] = 1;

        // Look at adjacent Node
        for (int j : adj[node])
        {
            // if neighbour node is already present in my path
            // cycle is present
            if (path[j] == 1)
                return 1;
            // if neighbour node is already visited . then dont check again - skip
            // if(visited[adj[node][j]] == 1)
            // continue;

            // if neighbour is nt visited check and detect cycle
            if (!visited[j] && DetectCycle(j, adj, path, visited))
                return 1;
        }
        path[node] = 0; // back tracking step
        return 0;
    }

    bool isCyclic(int V, vector<vector<int>> &adj)
    {

        vector<int> path(V, 0);
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && DetectCycle(i, adj, path, visited))
                return 1;
        }
        return 0;
    }
};
//! BFS &  Kahn's Algorithm
class Solution
{
public:
    // TC = O(V + E) // SC = O(V)
    bool isCyclic(int V, vector<vector<int>> &adj)
    {
        // USING KHAN'S ALGO -
        vector<int> Indeg(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                Indeg[adj[i][j]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (Indeg[i] == 0) // put in q
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if (!Indeg[adj[node][j]])
                    q.push(adj[node][j]);
            }
        }
        int count = ans.size();
        // if its a cyclic graph count != v  should be true
        // if count == v - Acyclic Graph
        return count != V;
    }
};