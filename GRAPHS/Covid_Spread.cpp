class Solution
{
public:
    int r;
    int c;

    // Directions for moving up, down, left, and right
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    // Function to check if the cell is valid
    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int helpaterp(vector<vector<int>> hospital)
    {
        r = hospital.size();    // Initialize class-level r
        c = hospital[0].size(); // Initialize class-level c

        // BFS
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j] == 2)
                {
                    q.push({i, j}); // Add all initially infected cells to the queue
                }
            }
        }

        int timer = 0; // Track time taken to infect all patients
        while (!q.empty())
        {
            int curr_patient = q.size();
            bool infected = false; // Track if any new patient is infected during this iteration

            while (curr_patient--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // Check all 4 possible directions
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    // If a valid, uninfected patient is found
                    if (valid(ni, nj) && hospital[ni][nj] == 1)
                    {
                        hospital[ni][nj] = 2; // Infect the patient
                        q.push({ni, nj});     // Add to the queue
                        infected = true;      // Mark that an infection occurred
                    }
                }
            }

            // Increment timer only if an infection occurred
            if (infected)
            {
                timer++;
            }
        }

        // Check if any uninfected patient remains
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j] == 1)
                {
                    return -1; // Uninfected patient found
                }
            }
        }

        return timer; // Return total time taken
    }
};
