//! Topological sort using BFS
class Solution
{
public:
    // Khan's algorithm
    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> ans;
        vector<int> Indeg(V, 0); // Find & store the indegree of every vertex

        for (int i = 0; i < V; i++)
            for (int j = 0; j < adj[i].size(); j++)
                Indeg[adj[i][j]]++;

        // push all the Nodes of 0 indegree in Q
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (Indeg[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            // Neighbour ki indegree ko decrease by 1
            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if (Indeg[adj[node][j]] == 0)
                    q.push(adj[node][j]);
            }
        }
        return ans;
    }
};
