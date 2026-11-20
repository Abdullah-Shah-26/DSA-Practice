#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPairs(vector<int> &nums) {
    int n = nums.size();

    int ans = 0;
    unordered_map<int, int> freq;

    for (auto x : nums) {
      ans += freq[x];
      freq[x]++;

      string s = to_string(x);

      if (s.size() < 7)
        s.insert(s.begin(), 7 - s.size(), '0');

      // Genereate all unique str after 1 & 2 swaps
      unordered_set<string> st;

      for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {

          // First swap
          if (s[i] != s[j]) {
            swap(s[i], s[j]);
            st.insert(s);

            for (int i1 = 0; i1 < s.size(); i1++) {
              for (int j1 = i1 + 1; j1 < s.size(); j1++) {

                // Skip duplicate swaps
                if (i1 != i && j1 != j) {

                  // Second swap
                  if (s[i1] != s[j1]) {
                    swap(s[i1], s[j1]);
                    st.insert(s);
                    swap(s[i1], s[j1]);
                  }
                }
              }
            }

            swap(s[i], s[j]);
          }
        }
      }

      for (auto s : st)
        ans += freq[stoi(s)];
    }

    return ans;
  }
};