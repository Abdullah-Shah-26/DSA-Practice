class Solution
{
public:
    vector<int> findOrder(int N, vector<vector<int>> prereq)
    {
        // Adjacency list create Karo
        int P = prereq.size();
        vector<int> adj[N];
        vector<int> Indeg(N, 0);

        for (int i = 0; i < P; i++)
        {
            adj[prereq[i][1]].push_back(prereq[i][0]);
            Indeg[prereq[i][0]]++;
        }
        // Kahn's Algorithm
        // Indegree find karna

        queue<int> q;
        for (int i = 0; i < N; i++)
            if (!Indeg[i])
                q.push(i);
        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Look at neighbour
            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;

                if (Indeg[adj[node][j]] == 0)
                    q.push(adj[node][j]);
            }
        }
        vector<int> temp;
        return ans.size() == N ? ans : temp; // Directed Acyclic graph - all tasks will be completed
                                             // cyclic graph - all tasks won't be completed
    }
};