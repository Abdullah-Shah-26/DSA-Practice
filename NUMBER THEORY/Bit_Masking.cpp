#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);
/*
Problem: Find 2 workers with maximum common available days

Input format:
N                    <- Number of workers
count1 day1 day2 ... <- Worker 0: count of days, followed by each day (SAME LINE)
count2 day1 day2 ... <- Worker 1: count of days, followed by each day (SAME LINE)
...

Example:
4
3 1 4 7
2 5 10
3 2 8 15
1 20

This means:
- 4 workers total
- Worker 0: available 3 days (1, 4, 7)
- Worker 1: available 2 days (5, 10)
- Worker 2: available 3 days (2, 8, 15)
- Worker 3: available 1 day (20)

Output: Worker 0 and Worker 2 have 0 common days, etc...
*/

int main()
{
  fastio;

  // ============ STEP 1: READ INPUT ============
  int n;
  cin >> n; // Number of workers

  vector<int> masks(n, 0); // Bitmask for each worker

  for (int i = 0; i < n; i++)
  {
    int count;
    cin >> count; // How many days is worker i available?

    int mask = 0; // Start with empty bitmask

    for (int j = 0; j < count; j++)
    {
      int day;
      cin >> day;         // Read each available day
      mask |= (1 << day); // Set bit at position 'day' to 1
    }

    masks[i] = mask; // Store worker's availability as bitmask
  }

  // ============ STEP 2: FIND BEST PAIR ============
  int maxDays = 0;
  int bestWorker1 = -1;
  int bestWorker2 = -1;

  // Compare every pair of workers
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      // Bitwise AND: keeps only bits that are 1 in BOTH masks
      // This gives us the common available days
      int commonBits = (masks[i] & masks[j]);

      // Count how many bits are set to 1
      int commonDays = __builtin_popcount(commonBits);

      // Keep track of the pair with most common days
      if (commonDays > maxDays)
      {
        maxDays = commonDays;
        bestWorker1 = i;
        bestWorker2 = j;
      }
    }
  }

  // ============ STEP 3: PRINT ANSWER ============
  cout << "Best pair: Worker " << bestWorker1 << " and Worker " << bestWorker2 << endl;
  cout << "Common available days: " << maxDays << endl;

  return 0;
}

