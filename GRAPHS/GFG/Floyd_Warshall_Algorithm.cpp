#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &mat)
    {
        int n = mat.size();

        // Step 1: Initialize the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == -1)
                {
                    mat[i][j] = 1e9; // Represent unreachable paths with a large value
                }
                if (i == j)
                {
                    mat[i][j] = 0; // Distance to itself is always 0
                }
            }
        }

        // Step 2: Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++)
        { // Intermediate node
            for (int i = 0; i < n; i++)
            { // Source node
                for (int j = 0; j < n; j++)
                { // Destination node
                    // Check if both mat[i][k] and mat[k][j] are reachable
                    if (mat[i][k] < 1e9 && mat[k][j] < 1e9)
                    {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        // Step 3: Detect negative weight cycles
        for (int i = 0; i < n; i++)
        {
            if (mat[i][i] < 0)
            {
                // Mark all paths involving the negative cycle as unreachable
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (mat[i][j] < 1e9 && mat[j][k] < 1e9)
                        {
                            mat[j][k] = -1;
                        }
                    }
                }
            }
        }

        // Step 4: Replace large values (1e9) back with -1 to indicate unreachable paths
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1e9)
                {
                    mat[i][j] = -1;
                }
            }
        }
    }
};