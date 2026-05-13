#include <bits/stdc++.h>
using namespace std;

// TC = O(N Log N + N*L)

class TrieNode{
  public:
  TrieNode* child[26];
  vector<string> suggestions;

  TrieNode(){
    for(int i = 0; i < 26; i++){
      child[i] = NULL;
    }
  }
};

class Trie{
  private:
  TrieNode* root;
  
  public:
  Trie(){
    root = new TrieNode();
  }

  void insert(string &word){
    TrieNode* cur =  root;

    for(char &ch : word){
      int idx = ch - 'a';

      if(cur->child[idx] == NULL){
        cur->child[idx] = new TrieNode();
      }

      cur = cur->child[idx];

      // Storing top 3 lexico smallest words
      if(cur->suggestions.size() < 3){
        cur->suggestions.push_back(word);
      }
    }        
  } 

  vector<vector<string>> search(string &searchWord){
    vector<vector<string>> ans;
    TrieNode* cur = root;

    for(char &ch: searchWord){
      int idx = ch - 'a';

      if(cur == NULL || cur->child[idx] == NULL){
        cur = NULL; // All future suggestions also break
        ans.push_back({}); 
      }
      else if(cur->child[idx] != NULL){
        cur = cur->child[idx];
        ans.push_back(cur->suggestions);
      }
    }
    return ans;
  }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    sort(products.begin(), products.end()); // sorts products lexicographically    
    
    Trie trie;

    for(auto &p : products){
      trie.insert(p);
    }

    return trie.search(searchWord);
    }
};