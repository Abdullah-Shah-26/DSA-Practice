#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(N) || SC = O(N)

class Solution {
  public:
    int n;
    TreeNode* f(int &i, string &s, int depth){
      if(i >= n) return NULL;

      int j = i;

      while(j < n && s[j] == '-') j++;

      int dashes = j - i;

      if(dashes != depth) return NULL;

      i = j;
      int num = 0;
      while(i < n && isdigit(s[i])){
        num = num * 10 + (s[i] - '0');
        i++;
      }

      TreeNode *root = new TreeNode(num);
      root->left = f(i, s, depth+1);
      root->right = f(i, s, depth+1);

      return root;
    }

    TreeNode* recoverFromPreorder(string s) {
    n = s.size();
    int i = 0; 
    int depth = 0;
    return f(i, s, depth);    
    }
};