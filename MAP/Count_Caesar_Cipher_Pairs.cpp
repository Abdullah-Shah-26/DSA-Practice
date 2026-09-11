#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long countPairs(vector<string> &words) {
    int n = words.size();

    unordered_map<string, int> mp;
    unordered_map<string, int> t;

    for (auto &s : words)
      mp[s]++;

    ll cnt = 0;

    for (int i = 0; i < n; i++) {
      if (t.find(words[i]) != t.end())
        continue;

      // No of similar groups
      ll ans = 0;
      for (int j = 0; j < 26; j++) {
        string tf = words[i];

        for (int k = 0; k < tf.size(); k++) {
          int val = tf[k] - 'a';
          val = (val + j) % 26;
          tf[k] = (val + 'a');
        }

        t[tf]++;
        ans += mp[tf];
      }

      // No of pairs we can make with these groups = nC2 = (n * (n - 1))/2
      cnt += (ans * (ans - 1)) / 2;
    }

    return cnt;
  }
};