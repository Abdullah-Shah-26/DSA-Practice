#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Directions for moving up, down, left, and right
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    // Helper function to check if a cell is within bounds
    bool valid(int i, int j, int r, int c)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int orangesRotting(vector<vector<int>> &mat)
    {
        int r = mat.size();    // Number of rows
        int c = mat[0].size(); // Number of columns

        queue<pair<int, int>> q; // BFS queue
        int fresh_count = 0;     // Count of fresh oranges

        // Push all initially rotten oranges into the queue
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push({i, j}); // Add rotten orange to the queue
                }
                else if (mat[i][j] == 1)
                {
                    fresh_count++; // Count fresh oranges
                }
            }
        }

        // If there are no fresh oranges, return 0 (no time needed)
        if (fresh_count == 0)
        {
            return 0;
        }

        int timer = 0;

        // BFS to infect all neighboring fresh oranges
        while (!q.empty())
        {
            int curr_oranges = q.size();
            bool infected = false;

            while (curr_oranges--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // Check all 4 possible directions
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    // If the cell is valid and contains a fresh orange
                    if (valid(ni, nj, r, c) && mat[ni][nj] == 1)
                    {
                        mat[ni][nj] = 2;  // Infect the orange
                        q.push({ni, nj}); // Add the newly infected orange to the queue
                        fresh_count--;    // Reduce the count of fresh oranges
                        infected = true;
                    }
                }
            }

            // Increment the timer only if an infection occurred
            if (infected)
            {
                timer++;
            }
        }

        // If there are still fresh oranges left, return -1
        return (fresh_count == 0) ? timer : -1;
    }
};
