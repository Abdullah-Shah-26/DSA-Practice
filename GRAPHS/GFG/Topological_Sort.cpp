//! USING DFS -
class Solution
{
public:
    void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
    {
        visited[node] = 1;
        // look at its neighbour one by one .
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
                DFS(adj[node][j], adj, visited, s);
        }
        // after seeing all neighbours push in stack
        s.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        // DFS  find karooo
        vector<bool> visited(V, 0);
        stack<int> s;

        for (int i = 0; i < V; i++)
        { // visit all nodes
            if (!visited[i])
                DFS(i, adj, visited, s);
        }
        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};