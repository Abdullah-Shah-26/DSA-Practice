#include <bits/stdc++.h>
using namespace std;

// TC = O(N * L) + O(W * L) where N = size of dict | L = length of word | W = words in sentence
// SC = O(N * L)

class TrieNode{
  public:
  TrieNode* child[26];
  bool isEnd;

  TrieNode(){
    isEnd = false;
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
  
    void insert(string s){ // TC = O(L) | SC = O(L)
      TrieNode* cur = root;
      for(char &ch : s){
        int idx = ch - 'a';
        if(cur->child[idx] == NULL){
          cur->child[idx] = new TrieNode();
        }
        cur = cur->child[idx]; 
      }
      cur->isEnd = true;
    }

    string getRoot(string word){ // TC = O(L) | SC = O(L)
      TrieNode* cur = root;
      string pref = "";
     
     for(char &ch : word){
        int idx = ch - 'a';

        if(cur->child[idx] == NULL){
          // No shortest prefix exist
          return word; // Return original word
        }
        cur = cur->child[idx];

        pref += ch;

        if(cur->isEnd == true)
          return pref;
      }
      return word;
    }
};

class Solution {
  public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    Trie trie;

    for(string &s : dictionary){
      trie.insert(s);
    }    

    stringstream ss(sentence);
    string word;
    string ans;

    while(ss >> word){
      ans += trie.getRoot(word);
      ans += ' ';
    }

    ans.pop_back(); // remove extra space from last

    return ans;
    }
};