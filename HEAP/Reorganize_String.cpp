#include <bits/stdc++.h>
using namespace std;

// Greedy String Construction using MaxHeap

class Solution {
  public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
    int n = s.size();

    vector<int> freq(26, 0);
    for(char &ch : s){
      freq[ch - 'a']++; 

      if(freq[ch - 'a'] > (n + 1)/2){
        return "";
      }
    } 

    priority_queue<P> pq; // MaxHeap

    for(char ch = 'a'; ch <= 'z'; ch++){
      if(freq[ch-'a'] > 0){
        pq.push({freq[ch - 'a'], ch});
      }
    }

    string ans = "";
    while(pq.size() >= 2){
      auto [f1, ch1] = pq.top(); pq.pop();
      auto [f2, ch2] = pq.top(); pq.pop();

      ans += ch1;
      f1--;
      ans += ch2;
      f2--;

      if(f1 > 0) pq.push({f1, ch1});
      if(f2 > 0) pq.push({f2, ch2});
    }

    if(!pq.empty()){
      ans += pq.top().second;
    }

    return ans;
    }
};