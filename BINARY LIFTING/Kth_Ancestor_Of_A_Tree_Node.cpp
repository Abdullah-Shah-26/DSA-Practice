#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class TreeAncestor {
public:
    //      build      +  Q queries
    // TC = O(N Log N) + O(Q Log N)
    // SC = O(N Log N)

    static const int MAX = 20;
    vector<vector<int>> ancestor;
    TreeAncestor(int n, vector<int>& parent) {
      ancestor.assign(n, vector<int>(MAX, -1));

      // 2^0 = Immediate Parent
      for(int node = 0; node < n; node++){
        ancestor[node][0] = parent[node];
      }

      // Building Binary Lifting Table
      for(int pow = 1; pow < MAX; pow++){
        for(int node = 0; node < n; node++){
          int midAncestor = ancestor[node][pow - 1];

          if(midAncestor != -1){
            ancestor[node][pow] = ancestor[midAncestor][pow - 1]; 
          }
        }
      }
    }
    
    int getKthAncestor(int node, int k) {
        for(int pow = 0; k && node != -1; pow++){
          if(k & 1){ // Loop Until K != 0
            node = ancestor[node][pow];
          }
          k >>= 1; // k /= 2 // Keeps removing last bit
        }    
       return node;
    } 
};

//! ----------------------------------------------------------
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


const int MAXN =200005; 
const int LOG = 30;

int up[MAXN][LOG];
// Row - Node
// Col - Kth Ancestor

void dfs(BinaryTreeNode<int> *node, int parent){
    if(!node){
        return;
    }

    up[node->data][0] = parent;

    if(node->left){
        dfs(node->left, node->data);
    }
    if(node->right){
        dfs(node->right, node->data);
    }
}

int jump(int node, int k){

    for(int bit = 0; bit <LOG; bit++){
        if(k & (1 << bit)){
            if(node != -1){
                node = up[node][bit];
            }
        }
    }
    return node;
}

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    memset(up, -1, sizeof(up));

    dfs(root, -1);

    for(int j = 1; j < LOG; j++){
        for(int node = 1; node < MAXN; node++){
            if(up[node][j-1] != -1){
                up[node][j] = up[ up[node][j-1] ][j-1];
            }
        }
    }

    return jump(targetNodeVal, k);
}


*************************************************************/