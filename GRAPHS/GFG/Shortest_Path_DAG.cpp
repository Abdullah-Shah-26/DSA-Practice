class Solution
{
public:
    void DFS(int node, vector<pair<int, int>> adj[], stack<int> &s, vector<bool> &visited)
    {
        visited[node] = 1;

        // look at all of its neighbours
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j].first])
                DFS(adj[node][j].first, adj, s, visited);
        }
        s.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // ADJACENCY LIST CREATE KARO
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
        }
        // topological sort ( D F S - STACK )
        stack<int> s1;
        vector<bool> visited(N, 0);
        // NO need to apply topo sort for disconnected graph since we can t ever reach those node
        DFS(0, adj, s1, visited);
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;

        // stack empty karo
        while (!s1.empty())
        {
            int node = s1.top();
            s1.pop();

            // LOOK AT THE NEIGHBOURS
            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                dist[neighbour] = min(dist[neighbour], weight + dist[node]);
            }
        }
        // -1 - return this ans if u cant reach those nodes from 0
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};