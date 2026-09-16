#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      return true;

    return false;
  }

  string sortVowels(string s) {
    int n = s.size();

    // [char] -> [freq, first occurence]
    unordered_map<char, pair<int, int>> m;

    for (int i = 0; i < n; i++) {
      char ch = s[i];

      if (isVowel(ch)) {
        m[ch].first++; // Freq

        if (m[ch].first == 1) { // First occurence
          m[ch].second = i;
        }
      }
    }

    vector<pair<char, pair<int, int>>> v(m.begin(), m.end());

    sort(begin(v), end(v), [&](auto a, auto b) {
      if (a.second.first != b.second.first) // Freq different
        return a.second.first >
               b.second.first; // Keep the char with larger freq first

      // Else prefer char with earlier first occurence
      return a.second.second < b.second.second;
    });

    // Sorted vowel sequence
    string ans = "";
    for (auto &it : v) {
      for (int j = 0; j < it.second.first; j++)
        ans += it.first;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
      if (isVowel(s[i])) {
        s[i] = ans[j];
        j++;
      }
    }

    return s;
  }
};