#include <bits/stdc++.h>
using namespace std;

// KMP
class KMP{
private:
  vector<int> buildLps(string &pat){
    int m = pat.size();

    vector<int> lps(m);

    for(int i = 1, len = 0; i < m; ){

      if(pat[i] == pat[len]){
        lps[i++] = ++len;
      }

      else if(len){
        len = lps[len - 1];
      }

      else{
        lps[i++] = 0;
      }
    }

    return lps;
  }

public:
  vector<int> find(string &text, string &pat){
    int n = text.size();
    int m = pat.size();

    vector<int> lps =
      buildLps(pat);

    vector<int> ans;

    for(int i = 0, j = 0; i < n; ){

      if(text[i] == pat[j]){
        i++;
        j++;
      }

      if(j == m){
        ans.push_back(i - m);
        j = lps[j - 1];
      }

      else if(i < n && text[i] != pat[j]){

        if(j)
          j = lps[j - 1];

        else
          i++;
      }
    }

    return ans;
  }
};