#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN) | SC = O(1)

// Most freqent tasks forces spacing, which can be greedily filled by remaining tasks in order of their frequency

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);

    for(auto &ch : tasks) 
      freq[ch-'A']++;
  
    sort(begin(freq), end(freq));

    int maxFreq = freq[25]; // Ex: A A A -> 3

    int partitions = maxFreq - 1;   // A _ _ A _ _ A
                                    //   ^ ^   ^ ^
                                    // 2 partitions

    int idleSlots = partitions * n; // n = 2
                                    // Total empty slots = 2 * 2 = 4

    for(int i = 24; i >= 0; i--){
        idleSlots -= min(freq[i], partitions);
    }

    return tasks.size() + max(0, idleSlots);
  }
};