#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)

// tin[u] = start idx in euler
// tout[u] = end idx in euler
// flat[i] = depth of node whose euler idx is i 

class Solution {
public:
  vector<int> tin;
  vector<int> tout;
  vector<int> flat;

  int timer = 0;

  void dfs(TreeNode* node, int depth){
    if(!node) return;

    tin[node->val] = timer; 
  
    flat[timer] = depth;

    timer++;

    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);

    tout[node->val] = timer - 1;
  }

  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
  int n = 100001;
  
  tin.resize(n);
  tout.resize(n);
  flat.resize(n);

  dfs(root, 0);

  flat.resize(timer);

  int m = flat.size();

  vector<int> pref(m), suff(m);

  pref[0] = flat[0];

  for(int i = 1; i < m; i++)    
    pref[i] = max(pref[i - 1], flat[i]);

  suff[m-1] = flat[m-1];

  for(int i = m-2; i >= 0; i--)
    suff[i] = max(suff[i + 1], flat[i]);


  vector<int> ans;
  
  for(auto &u: queries){
    // Interval Removed : Since SubTree became Subarr
    //  L              R 
    // [tin[u]....tout[u]]

    int L = tin[u];
    int R = tout[u];
    
    // Remaining : 
    // Left : 0 --- pref[L - 1]
    // Right  : suff[R + 1] --- n

    int left = (L > 0) ? pref[L - 1] : 0;
    int right = (R + 1 < m) ? suff[R + 1] : 0;

    // Tree Ht after deleting : Max depth among nodes outside deleted subtree
    ans.push_back(max(left, right));
  }

  return ans;
  }
};