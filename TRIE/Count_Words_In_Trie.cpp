#include <bits/stdc++.h>
using namespace std;

// TC = O(N) where N = Total No of Nodes in Trie
// SC = O(H) where H = Height of Trie (Max depth)


class TrieNode {
  public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};


class Solution {
  public:
    int dfs(TrieNode* node){
        int cnt = 0;
        if(node->isEnd) cnt++;
        
        for(int i = 0; i < 26; i++){
            if(node->children[i] != NULL){
                cnt += dfs(node->children[i]);
            }
        }    
        return cnt;
    }
  
    int wordCount(TrieNode* root) {
    int cnt = 0;
    
    for(int i = 0; i < 26; i++){
        if(root->children[i] != NULL){
            cnt += dfs(root->children[i]);
        }
    }
    
    return cnt;
    }
};