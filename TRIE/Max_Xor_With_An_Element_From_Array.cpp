#include <bits/stdc++.h>
using namespace std;

// TC = O(NLogN + QLogQ + (N + Q)*32)

class TrieNode{
  public:
  TrieNode* child[2];

  TrieNode(){
    child[0] = child[1] = NULL;
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
    }
  }

  int getMaxXor(int num){
    TrieNode* cur = root;
    int ans = 0;

    for(int i = 31; i >= 0; i--){
      int bit = (num >> i) & 1;

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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int k = queries.size();
    vector<int> ans(k, -1);

    Trie trie;

    auto cmp = [&](auto &a, auto &b){
      return a[1] < b[1];
    };

    for(int i = 0; i < k; i++){
      queries[i].push_back(i);
    }

    sort(nums.begin(), nums.end());
    sort(queries.begin(), queries.end(), cmp);

    int j = 0;
    for(auto &q : queries){
      int x = q[0];
      int m = q[1];
      int idx = q[2];

      while(j < n && nums[j] <= m){
        trie.insert(nums[j]);
        j++;
      }

      if(j == 0) // No valid ans
        ans[idx] = -1;
      else 
        ans[idx] = trie.getMaxXor(x);
    }

    return ans;    
    }
};