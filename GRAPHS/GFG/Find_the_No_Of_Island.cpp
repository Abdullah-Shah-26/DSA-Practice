class Solution
{
public:
    int r;
    int c;

    // Moving in 8 possible directions
    int row[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int col[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    int countIslands(vector<vector<char>> &grid)
    {
        r = grid.size();
        c = grid[0].size();

        int count = 0;
        queue<pair<int, int>> q;
        // check 1 in our grid & convert all 1 to 0 (we are uniting all small island into 1 and its counted as 1)
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 'L')
                {
                    count++;
                    q.push({i, j});
                    // converting all 1(L) to 0 (W)
                    grid[i][j] = 'W';
                    while (!q.empty())
                    {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++)
                        {
                            if (valid(new_i + row[k], new_j + col[k]) && grid[new_i + row[k]][new_j + col[k]] == 'L')
                            {
                                // make it as 0(W)
                                grid[new_i + row[k]][new_j + col[k]] = 'W';
                                q.push({new_i + row[k], new_j + col[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};