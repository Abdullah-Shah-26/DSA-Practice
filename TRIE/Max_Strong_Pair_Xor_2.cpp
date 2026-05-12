#include <bits/stdc++.h>
using namespace std;

// Sliding Window - 2 Pointer + Xor Trie
// TC = O(NLogN + N*20) | SC = O(N * 20)

class TrieNode{
  public:
  TrieNode* child[2];
  int cnt; // Each bit should now how many no's used me

  TrieNode(){
    child[0] = NULL;
    child[1] = NULL;
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

   for(int i = 20; i >= 0; i--){
    int bit = (num >> i) & 1;

    if(cur->child[bit] == NULL){
      cur->child[bit] = new TrieNode();
    }
    cur = cur->child[bit];
    cur->cnt++;
   }
  }

  int getMaxXor(int num){
    TrieNode* cur = root;
    int ans = 0;

    for(int i = 20; i >= 0; i--){
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

  void remove(int num){
    TrieNode* cur = root;

    for(int i = 20; i >= 0; i--){
      int bit = (num >> i) & 1;
      cur = cur->child[bit];
      cur->cnt--;
    }
  }
};

/*

Sort : 
x = a[i], y = a[j]
Now x <= y so min(x,y) = x
Now |x - y| = y - x
Condition Transforms from |x-y| <= min(x,y) to 
[ y  -  x ] <= x 
a[j] - a[i] <= a[i] is Valid Pair 
a[j] - a[i] > a[i] is Invalid Pair

*/

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    Trie trie;

    int ans = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
      trie.insert(nums[r]);

      while(nums[r] - nums[l] > nums[l]){
        trie.remove(nums[l]);
        l++;
      }
      ans = max(ans, trie.getMaxXor(nums[r]));
    }

    return ans;
    }
};
