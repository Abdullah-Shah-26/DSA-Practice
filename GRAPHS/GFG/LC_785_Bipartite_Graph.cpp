//! DFS - METHOD
class Solution
{
public:
    // Function to check if a graph is bipartite using DFS
    bool checkBip(int node, vector<vector<int>> &adj, vector<int> &color)
    {
        // Look at all neighbors of the current node
        for (int neighbor : adj[node])
        {
            // If the neighbor is not colored
            if (color[neighbor] == -1)
            {
                // Assign the opposite color to the neighbor
                color[neighbor] = 1 - color[node];
                // Recursively check the neighbor
                if (!checkBip(neighbor, adj, color))
                    return false;
            }
            // If the neighbor is already colored and has the same color as the current node
            else if (color[neighbor] == color[node])
            {
                return false; // Not bipartite
            }
        }
        return true;
    }

    // Function to check if the entire graph is bipartite
    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        // Step 1: Construct the adjacency list from edges
        vector<vector<int>> adj(V); // Adjacency list
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // Since this is an undirected graph
        }

        vector<int> color(V, -1); // Initialize all nodes as uncolored

        // Step 2: Check all components of the graph
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {                 // If the node is not yet colored
                color[i] = 0; // Assign the first color
                if (!checkBip(i, adj, color))
                    return false; // Not bipartite
            }
        }
        return true; // Bipartite
    }
};
//! BFS - METHOD
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &adj)
    {
        // B - F - S
        int V = adj.size();
        vector<int> color(V, -1);
        queue<int> q;
        for (int i = 0; i < V; i++) // handles the edge case of disconnected graphs
        {
            if (color[i] == -1)
            {
                q.push(i);
                color[i] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < adj[node].size(); j++)
                    {
                        // Neighbour nodes ko color assign nai hay
                        if (color[adj[node][j]] == -1)
                        { // assign them color opposite to the node
                            color[adj[node][j]] = (color[node] + 1) % 2;
                            q.push(adj[node][j]);
                        }
                        // color is already assigned
                        else
                        {
                            // if neighbour has same color as node then its not Biparite graph
                            if (color[node] == color[adj[node][j]])
                                return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};
