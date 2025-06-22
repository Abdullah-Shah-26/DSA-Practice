class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prereq)
    {
        // Code here
        // Adjacency list create Karo
        vector<int> adj[N];
        vector<int> Indeg(N, 0);

        for (int i = 0; i < P; i++)
        {
            adj[prereq[i].second].push_back(prereq[i].first);
            Indeg[prereq[i].first]++;
        }
        // Kahn's Algorithm
        // Indegree find karna

        queue<int> q;
        for (int i = 0; i < N; i++)
            if (!Indeg[i])
                q.push(i);
        int count = 0; // kitne size ka Topological sort hoga

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            // Look at neighbour
            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;

                if (Indeg[adj[node][j]] == 0)
                    q.push(adj[node][j]);
            }
        }
        return count == N; // Directed Acyclic graph - all tasks will be completed
                           // cyclic graph - all tasks won't be completed
    }
};