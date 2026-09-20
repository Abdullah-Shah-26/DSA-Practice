#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> printVertically(string s) {
    stringstream ss(s);

    string word;
    vector<string> words;

    // No of vertically printed words
    int maxL = 0;

    while (ss >> word) {
      int L = word.size();
      maxL = max(maxL, L);
      words.push_back(word);
    }

    vector<string> ans(maxL);

    for (int i = 0; i < maxL; i++) {
      for (auto &w : words) {
        if (i < w.size())
          ans[i] += w[i];
        else
          ans[i] += ' ';
      }

      while (ans[i].back() == ' ')
        ans[i].pop_back();
    }

    return ans;
  }
};