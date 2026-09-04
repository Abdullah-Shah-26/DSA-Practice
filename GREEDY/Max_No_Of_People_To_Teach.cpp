#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {
    int ans = 0;

    unordered_set<int> sad;

    for (auto it : friendships) {
      int u = it[0] - 1;
      int v = it[1] - 1;

      unordered_set<int> st(begin(languages[u]), end(languages[u]));

      bool canTalk = false;

      for (int x : languages[v]) {
        if (st.find(x) != st.end()) {
          canTalk = true;
          break;
        }
      }

      if (!canTalk) {
        sad.insert(u);
        sad.insert(v);
      }
    }

    // Find max known language among sad users
    unordered_map<int, int> mp;

    int maxFreq = 0;

    for (auto user : sad) {
      for (int lang : languages[user]) {
        mp[lang]++;
        maxFreq = max(maxFreq, mp[lang]);
      }
    }

    return sad.size() - maxFreq;
  }
};