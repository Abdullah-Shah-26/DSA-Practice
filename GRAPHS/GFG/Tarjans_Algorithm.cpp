class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low,
             stack<int> &s, vector<bool> &InStack, vector<vector<int>> &ans, int &timer)
    {
        visited[node] = true;
        disc[node] = low[node] = timer;
        s.push(node);
        InStack[node] = true;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                ++timer;
                DFS(neigh, adj, visited, disc, low, s, InStack, ans, timer);
                low[node] = min(low[node], low[neigh]);
            }
            else if (InStack[neigh]) {
                low[node] = min(low[node], disc[neigh]);
            }
        }

        // if we're at the root of an SCC, pop until we get back to 'node'
        if (disc[node] == low[node]) {
            vector<int> temp;
            while (!s.empty() && s.top() != node) {
                temp.push_back(s.top());
                InStack[s.top()] = false;
                s.pop();
            }
            temp.push_back(node);
            InStack[node] = false;
            s.pop();
            sort(temp.begin(), temp.end()); // each SCC in sorted order
            ans.push_back(temp);
        }
    }

    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
       vector<vector<int>> ans;              // <-- fixed: added missing '>>'
       vector<int> disc(V), low(V);
       vector<bool> visited(V, false), InStack(V, false);
       stack<int> s;
       int timer = 0;

       for (int i = 0; i < V; ++i) {
           if (!visited[i])
               DFS(i, adj, visited, disc, low, s, InStack, ans, timer);
       }
       sort(ans.begin(), ans.end());         // sort the list of SCCs
       return ans;
    }
};