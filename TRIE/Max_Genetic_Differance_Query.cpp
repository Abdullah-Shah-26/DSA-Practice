#include <bits/stdc++.h>
using namespace std;

// TC = O(N + Q)*32 |  SC = O(N*32 + Q)

// Xor Trie

class TrieNode{
  public:
  TrieNode* child[2];
  int cnt ;

  TrieNode(){
    child[0] = child[1] = NULL;
    cnt = 0;
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

    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

      if(cur->child[bit] == NULL){
        cur->child[bit] = new TrieNode();
      }
      cur = cur->child[bit];
      cur->cnt++;
    }
  }

  void remove(int num){
    TrieNode* cur = root;

    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

      if(cur->child[bit] != NULL && cur->child[bit]->cnt > 0){
        cur = cur->child[bit];
        cur->cnt--;
      }
    }
  }

  int getMaxXor(int num){
    TrieNode* cur = root;
    int ans = 0;

    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

      if(cur->child[!bit] != NULL && cur->child[!bit]->cnt > 0){
        ans |= (1 << i);
        cur = cur->child[!bit];
      }
      else if(cur->child[bit] != NULL && cur->child[bit]->cnt > 0){
        cur = cur->child[bit];
      }
    }

    return ans;
  }
};


class Solution {
  public:
    vector<vector<int>> adj;
    vector<vector<pair<int,int>>> queryByNode; 
    vector<int> ans;
    Trie trie;

    // Current DFS path contains all ancestors of the current node
    // (root -> ... -> node).

    // We insert nodes while moving down the DFS and remove them
    // while backtracking, so trie always contains exactly the valid ancestors for the current node.

    // Queries are grouped by node, therefore when DFS reaches a node,
    // we can directly query the trie to get maximum XOR with `val`.

    void dfs(int u){
      trie.insert(u);

      for(auto &[val, i] : queryByNode[u]){
        ans[i] = trie.getMaxXor(val);
      }

      // Go to children of node
      for(int v : adj[u]){
        dfs(v);
      }

      // clear path while backtracking
      trie.remove(u); 
    }
    
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
      int n = parents.size();
      adj.resize(n);
      int root = -1;

      for(int i = 0; i < n; i++){
        if(parents[i] == -1){
          root = i;
        }
        else{
          adj[parents[i]].push_back(i);
        }
      }

      queryByNode.resize(n);

      for(int i = 0; i < queries.size(); i++){
        int node = queries[i][0];
        int val = queries[i][1];

        queryByNode[node].push_back({val, i});
      }

      ans.resize(queries.size());

      dfs(root);

      return ans;
    }
};