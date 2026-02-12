class Solution {
public:
    static const int MOD = 1e9 + 7;
  // TC = O(N * M * 16)
  // SC = O(M * 16)
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>prev(m, vector<int>(16));

        for(int i = 0; i < n; i++) {
           
            vector<vector<int>>cur(m, vector<int>(16));
            for(int j = 0; j < m; j++) {

                 if(i == 0 && j == 0) {
                    cur[0][grid[0][0]] = 1;
                    continue;
                }
                for(int x = 0; x < 16; x++) {

                    if(i > 0) {
                        int prev_x = x ^ grid[i][j];
                        cur[j][x] = (cur[j][x] + prev[j][prev_x]) % MOD;
                    }

                    if(j > 0) {
                        int prev_x = x ^ grid[i][j];
                        cur[j][x] = (cur[j][x] + cur[j-1][prev_x]) % MOD;
                    }
                }
            }
            prev = cur;
        }

        return prev[m-1][k];
    }
};
