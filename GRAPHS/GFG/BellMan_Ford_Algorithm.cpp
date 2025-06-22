class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {

        // for edges not directly connected distance = 100000000 = 1e8
        vector<int> dist(V, 100000000);

        dist[src] = 0; // distance from source to source is 0

        // step1 - release all the edges V - 1 times
        // step2 - release edges once more for cycle detection
        int e = edges.size();
        // Release all the edges
        for (int i = 0; i < V - 1; i++)
        {
            bool flag = 0; // avoid releasing edges multiple times if weight doesnt get changed

            for (int j = 0; j < e; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];

                // edge case handling we skip infinity(10^8 ie 1e8) - somesmallno
                // we treat this as 1e8 since it wouldnt make much difference
                if (dist[u] == 1e8)
                    continue;

                if (dist[u] + weight < dist[v])
                {
                    flag = 1; // weight changed
                    dist[v] = dist[u] + weight;
                }
            }
            if (!flag)       // if there is no change in distances(weights) after releasing edges return ans
                return dist; /// don't follow all steps
        }

        // step 2: Relax once more if weight changes this time  cycle detected
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            // Edge case
            if (dist[u] == 1e8)
                continue;

            if (dist[u] + weight < dist[v])
            {
                vector<int> ans;   // Cycle detected
                ans.push_back(-1); // ans not possible
                return ans;
            }
        }
        return dist;
    }
};