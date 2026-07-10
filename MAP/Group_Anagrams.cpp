#include <bits/stdc++.h>
using namespace std;

//! TC = O(N*K) // K - Avg Len of each string
//! SC = O(N*K)

class Solution {
public:
  string generate(string &word) {
    string key(26, 0); //! Using string buffer to store freq of each char

    for (char &ch : word)
      key[ch - 'a']++;

    return key;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    int n = strs.size();

    unordered_map<string, vector<string>> m;

    for (int i = 0; i < n; i++) {
      string word = strs[i];
      string hash = generate(word);

      m[hash].push_back(word);
    }

    vector<vector<string>> ans;

    for (auto &it : m) {
      ans.push_back(it.second);
    }

    return ans;
  }
};