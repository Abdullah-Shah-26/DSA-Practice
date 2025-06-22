class Solution
{
public:
    // tc = O(n * m)
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int N, int M)
    {
        return i >= 0 && i < N && j >= 0 && j < M;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // Use Simple B F S

        // edge case - source & destination same
        if (X == 0 && Y == 0)
            return 0;

        /// edge case - source is 0 - we cannot travel
        if (A[0][0] == 0)
            return -1;

        // row col step
        queue<pair<int, int>> q;
        q.push({0, 0});
        int step = 0;
        A[0][0] = 1; // making visited 0

        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {

                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                // Can move up down left right
                for (int k = 0; k < 4; k++)
                {
                    int new_i = i + row[k];
                    int new_j = j + col[k];

                    // visit nodes that are in A (given mat) and  arent visited and valid
                    if (valid(new_i, new_j, N, M) && A[new_i][new_j])
                    {
                        // check for the destination
                        if (new_i == X && new_j == Y)
                            return step + 1; // answer found

                        A[new_i][new_j] = 0;
                        q.push({new_i, new_j});
                    }
                }
            }
            step++; // when count value = 0
        }

        return -1;
    }
};