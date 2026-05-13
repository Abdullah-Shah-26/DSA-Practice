#include <bits/stdc++.h>
using namespace std;

// TC = O(N * L) | SC = O(N * L)

using ll = long long;

class TrieNode{
  public: 
  unordered_map<int, TrieNode*> child;
  int cnt = 0;
};

class Trie{
  private:
  TrieNode* root;

  public:
  Trie(){
     root = new TrieNode();
  }

  ll insertAndCnt(string &s){
    int n = s.size();
    ll matches = 0;

    TrieNode* cur = root;

    for(int i = 0; i < n; i++){
      int front = s[i] - 'a';
      int back = s[n-i-1] - 'a';

      // unique key for {frontChar, backChar}
      int key = front * 26 + back;

      if(cur->child.find(key) == cur->child.end()){
        cur->child[key] = new TrieNode();
      }
      
      cur = cur->child[key];
      matches += cur->cnt;
    }
    cur->cnt++;
    return matches;
  }
};

class Solution {
public:
    ll countPrefixSuffixPairs(vector<string>& words) {
    ll ans = 0;
    Trie trie;

    for(string &s : words){
      ans += trie.insertAndCnt(s);
    } 

    return ans; 
    }
};