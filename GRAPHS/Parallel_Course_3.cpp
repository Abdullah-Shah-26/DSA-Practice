class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        // create a adjacency list
        vector<int> adj[n];

        for (int i = 0; i < relations.size(); i++)
        {
            // Convert them into 0 based indexing
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }
        // Kahn's Algorithm
        vector<int> Indeg(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                Indeg[adj[i][j]]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (Indeg[i] == 0)
                q.push(i);

        // Maximum time to complete previous course
        vector<int> CourseTime(n, 0);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if (!Indeg[adj[node][j]])
                    q.push(adj[node][j]);

                // Maximum time to complete previous course + present course
                CourseTime[adj[node][j]] = max(CourseTime[node] + time[node], CourseTime[adj[node][j]]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, CourseTime[i] + time[i]);
        }
        return ans;
    }
};