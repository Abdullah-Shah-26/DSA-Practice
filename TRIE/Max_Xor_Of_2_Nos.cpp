#include <bits/stdc++.h>
using namespace std;

// TC = O(N * 32) | SC = O(N * 32)

class TrieNode{
  public:
  TrieNode* child[2];

  TrieNode(){
    child[0] = NULL;
    child[1] = NULL; 
  }
};

class Trie{
  private:
  TrieNode* root;

  public:
  Trie(){
    root = new TrieNode();
  }

  void insert(int num){
    TrieNode* cur = root;

    // MSB to LSB cause higher bits contribute more value
    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

      if(cur->child[bit] == NULL)
        cur->child[bit] = new TrieNode(); 

      cur = cur->child[bit];
    }  
  }

  int getMaxXor(int num){
    TrieNode* cur = root;
    int ans = 0;

    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

      // Xor maximizes if we have opposite value
      if(cur->child[!bit] != NULL){
        ans |= (1 << i);
        cur = cur->child[!bit];
      }
      else{
        cur = cur->child[bit];
      }
    }

    return ans;
  }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
    Trie trie;

    for(int x : nums)
      trie.insert(x);   

    int ans = 0;

    for(int x : nums)
      ans = max(ans, trie.getMaxXor(x));

    return ans;
    }
};