class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int N = adj.size();
        // array storing distance b/w nodes
        vector<int> dist(N, -1);
        vector<bool> visited(N, 0);

        // BFS
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        visited[src] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Look at all its neighbours
            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbour = adj[node][j];
                // if neighbour is already visited  skip
                if (visited[neighbour])
                    continue;

                visited[neighbour] = 1;
                q.push(neighbour);
                dist[neighbour] = dist[node] + 1;
            }
        }
        return dist;
    }
};