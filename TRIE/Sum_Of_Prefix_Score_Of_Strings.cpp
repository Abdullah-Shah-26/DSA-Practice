#include <bits/stdc++.h>
using namespace std;

// TC = O(N * L) | SC = O(N * L * 26)

class TrieNode{
  public:
  int cnt;
  TrieNode* child[26];

  TrieNode(){
    cnt = 0;
    for(int i = 0; i < 26; i++)
      child[i] = NULL;
  }
};

class Trie{
  private:
  TrieNode* root;

  public:
  Trie(){
    root = new TrieNode();
  }

  void insert(string &s){
    TrieNode* cur = root;

    for(char &ch : s){
      int i = ch - 'a';

      if(cur->child[i] == NULL)
        cur->child[i] = new TrieNode();

      cur = cur->child[i];
      cur->cnt++;
    }
  }

  int getScore(string &s){
    TrieNode* cur = root;
    int score = 0;

    for(char &ch : s){
      int i = ch - 'a';

      if(cur->child[i] == NULL) 
        return score;

      cur = cur->child[i];
      score += cur->cnt;
    }

    return score;
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string>& words) {
  Trie trie;

  for(auto &s : words)
    trie.insert(s);

  vector<int> ans(words.size(), 0);
  
  for(int i = 0; i < words.size(); i++){
    ans[i] = trie.getScore(words[i]);
  }

  return ans;
  }
};