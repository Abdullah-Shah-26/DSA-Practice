//! METHOD 1 - TLE
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Create an adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            adj[u].push_back({v, weight});
        }

        vector<bool> Explored(V, 0);
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        // Select a node which is not explored yet and its distance value is min
        int count = V;
        while (count--)
        {
            int node = -1, value = INT_MAX; // intially assuming a node and its value
            for (int i = 0; i < V; i++)
            {
                if (!Explored[i] && dist[i] < value)
                {
                    node = i;
                    value = dist[i];
                }
            } // marking node as expolored
            Explored[node] = 1;

            // RELAX THE EDGES - SEE ALL THE EDGES ONE BY ONE
            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;

                if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
                { // update the value of neighbour
                    dist[neighbour] = dist[node] + weight;
                }
            }
        }
        return dist;
    }
};
//! METHOD 2 - USING PRIORITY QUEUE
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Create an adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            adj[u].push_back({v, weight});
        }

        vector<bool> Explored(V, 0);
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        p.push({0, src});

        // Select a node which is not explored yet and its distance value is min
        while (!p.empty())
        {
            int node = p.top().second;
            p.pop();

            if (Explored[node] == 1) // ignore explored nodes
                continue;

            Explored[node] = 1;

            // RELAX THE EDGES - SEE ALL THE EDGES ONE BY ONE
            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;

                if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
                { // update the value of neighbour
                    dist[neighbour] = dist[node] + weight;
                    p.push({dist[neighbour], neighbour});
                }
            }
        }
        return dist;
    }
};