#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

struct Node{
  int data;
  Node* left, *right;
  Node(): data(0), left(NULL), right(NULL){}
};

class Solution {
  public:
    // TC = O(N)
    // SC = O(N) = O(N)
  
    void solve(Node* root, int &node, bool &found, vector<int>&values){
        
        if(!root){
            return;
        }
        
        if(root->data == node){
            found = true;
            return;
        }
        
        solve(root->left, node, found, values);
        
        if(found){
            values.push_back(root->data);
            return;
        }
        
        solve(root->right, node, found, values);
        
        if(found){
            values.push_back(root->data);
            return;
        }
    }
      
    int kthAncestor(Node *root, int k, int node) {
        bool found = 0;
        vector<int>values;
        
        solve(root, node, found, values);
        
        if(values.size() < k){
            return -1;
        }
        
        return values[k - 1];
    }
};

//* Approach 2
class Solution {
  public:
    // TC = O(N)
    // SC = O(N)
  
    bool solve(Node *root, int &cnt, int &node, int &val){
        if(!root){
            return;
        }
        
        if(root->data == node){
            return 1;
        }
        
        int l = solve(root->left, cnt, node, val);
        int r = solve(root->right, cnt, node, val);
        
        if(l || r){
            cnt--;
            
            if(cnt == 0){
                val = root->data;
            }
            return 1;
        }
        
        return 0;
    }
  
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        int cnt = k;
        int val = -1;
        
        solve(root, cnt, node, val);
        
        return val;
    }
};