class Solution
{
public:
    //! DFS-based cycle detection UNDIRECTED GRAPH .... - Failing Test Case CAUSE I THOUGHT
    //! ADJ LIST WAS GIVEN BUT EDGES WERE GIVEN
    // Parameters:
    bool CycleDetect(int node, int parent, const vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true; // Mark the current node as visited

        // Explore all neighbors of the current node.
        for (int j = 0; j < adj[node].size(); j++)
        {
            int neighbor = adj[node][j];
            // Skip the edge going back to the parent.
            if (neighbor == parent)
                continue;
            // If the neighbor is already visited, a cycle is found.
            if (visited[neighbor])
                return true;
            // Recursively check for cycles from this neighbor.
            if (CycleDetect(neighbor, node, adj, visited))
                return true;
        }
        // No cycle detected from this path.
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &adj)
    {
        // Create a visited array with V elements, all initially false.
        vector<bool> visited(V, false);

        // For disconnected graphs, try starting DFS from every unvisited vertex.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && (CycleDetect(i, -1, adj, visited)))
            {
                return 1;
            }
        }
        // If no component contains a cycle, return false.
        return false;
    }
};