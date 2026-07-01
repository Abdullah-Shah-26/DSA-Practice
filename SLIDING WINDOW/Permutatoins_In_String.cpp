#include <bits/stdc++.h>
using namespace std;

// Almost same as - Find all anagrams in a String

// Sliding Window + HashMap/Freq Array
// TC = O(N) | SC = O(1)

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
  int n = s1.size();
  int m = s2.size();

  if(n > m) return false;

  vector<int> freq1(26, 0);
  vector<int> freq2(26, 0);

  for(int i = 0; i < n; i++){
    freq1[s1[i]-'a']++;
  }

  int l = 0;
  for(int r = 0; r < m; r++){
    freq2[s2[r]-'a']++;

    if(r - l + 1 > n){
      freq2[s2[l]-'a']--;
      l++;
    }

    if(freq1 == freq2) return true;
  }

  return false;
  }
};