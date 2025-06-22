class Solution
{
public:
    // Recursive Method - TLE `
    // TC = O(V+E)
    // SC = O(V)
    void DFS(int node, vector<vector<int>> adj, vector<int> &ans, vector<bool> &visited)
    {
        // mark node as visited and push in ans
        visited[node] = 1;
        ans.push_back(node);

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
                DFS(neighbour, adj, ans, visited);
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        // 1 DFS visits all the unvisited neighbour 1 by 1
        // 2 Explore all paths and repeat step 1 // recursion
        // 3 If all the paths are explored it will return from where it
        // has been called
        int v = adj.size();
        vector<bool> visited(v, 0);
        vector<int> ans;

        if (v == 0)
            return ans;

        DFS(0, adj, ans, visited);
        return ans;
    }
};
//! USING STACK
class Solution
{
public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<int> ans;            // Stores the final DFS traversal
        int V = adj.size();         // Number of vertices
        vector<bool> visited(V, 0); // Visited array to track visited nodes
        stack<int> st;              // Stack to simulate DFS traversal

        st.push(0); // Start DFS from node 0

        while (!st.empty())
        {
            int vertex = st.top(); // Get the current node
            st.pop();

            if (!visited[vertex])
            {
                ans.push_back(vertex);  // Add the node to the answer
                visited[vertex] = true; // Mark the node as visited
            }

            // Push neighbors in reverse to maintain left-to-right traversal order
            for (int i = adj[vertex].size() - 1; i >= 0; i--)
            {
                int neighbor = adj[vertex][i];

                // If neighbor hasn't been visited, push it onto the stack
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }

        return ans; // Return the DFS traversal result
    }
};