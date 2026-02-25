#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }


//* Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};


// TC = O(N)
// SC = O(Ht of Tree  )

class Solution {
  public:
    void solve(struct Node* root, int node, bool &found, vector<int>&values){
        if(!root){
            return;
        }
        
        if(root->data == node){
            found = 1;
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
  
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        bool found = false;
        vector<int>values;
        
        solve(root, target, found, values);
        
        return values;
    }
};