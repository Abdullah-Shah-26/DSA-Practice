#include <bits/stdc++.h>
using namespace std;

// TC = O(N * 26)

class Solution {
public:
  string ans = "";

  bool solve(string &cur, vector<int> &cnt, string &target, int i,
             bool greater) {
    if (i == target.size()) {
      if (greater) {
        ans = cur;
        return true;
      }
      return false;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (cnt[ch - 'a'] == 0)
        continue;

      if (greater == false && ch < target[i])
        continue;

      // Do
      cur.push_back(ch);
      cnt[ch - 'a']--;

      bool isGreater = greater || (ch > target[i]);

      // Explore
      if (solve(cur, cnt, target, i + 1, isGreater))
        return true;

      // Undo
      cnt[ch - 'a']++;
      cur.pop_back();
    }

    return false;
  }

  string lexGreaterPermutation(string s, string target) {
    vector<int> cnt(26, 0);

    for (char ch : s)
      cnt[ch - 'a']++;

    string cur;

    solve(cur, cnt, target, 0, false);

    return ans;
  }
};

// Palindromic Permutation :

class Solution {
public:
  int halfLen;
  char mid = '#';
  string ans = "";

  bool solve(string &cur, string &target, vector<int> &freq, int i,
             bool greater) {

    if (cur.size() == halfLen) {
      string candidate = cur;
      string rightHalf = cur;
      reverse(begin(rightHalf), end(rightHalf));

      if (mid != '#')
        candidate += mid;

      candidate += rightHalf;

      if (candidate > target) {
        ans = candidate;
        return true;
      }

      return false;
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (freq[ch - 'a'] == 0)
        continue;

      if (!greater && ch < target[i])
        continue;

      cur.push_back(ch);
      freq[ch - 'a']--;

      bool newGreater = greater || (ch > target[i]);

      if (solve(cur, target, freq, i + 1, newGreater))
        return true;

      freq[ch - 'a']++;
      cur.pop_back();
    }

    return false;
  }

  string lexPalindromicPermutation(string s, string target) {
    int n = s.size();

    vector<int> freq(26);

    for (char &ch : s)
      freq[ch - 'a']++;

    // A palindrome can have at most one odd frequency.
    int odd = 0;

    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (freq[ch - 'a'] & 1) {
        odd++;
        mid = ch;
      }
    }

    if (odd > 1)
      return "";

    // We only need half the characters.
    for (char ch = 'a'; ch <= 'z'; ch++)
      freq[ch - 'a'] /= 2;

    string cur;
    halfLen = n / 2;

    if (!solve(cur, target, freq, 0, false))
      return "";

    return ans;
  }
};