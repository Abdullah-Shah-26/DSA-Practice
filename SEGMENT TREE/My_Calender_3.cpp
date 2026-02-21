#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

static const int MOD = 1'000'000'007;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Dynamic Segment Tree + Lazy Propogation

struct Node{
  int val = 0; // Max overlapping inside this segment
  int lazy = 0; // pending increment
  Node* left = NULL;
  Node* right = NULL;
};

void push(Node* node){
  
  // Create children if they dont exist
  if(!node->left){
    node->left = new Node();
  }

  if(!node->right){
    node->right = new Node();
  }

  // If curNode has pending updates

  if(node->lazy != 0){
    // Apply pending updates to children

    node->left->val += node->lazy;
    node->right->val += node->lazy;

    // pass lazy updates to grandchildren
    node->left->lazy  += node->lazy;
    node->right->lazy += node->lazy;


  // Clear Lazy Debt
  node->lazy = 0;
  }

}

void update(Node *node, int st, int end,int l,int r, int val){
  // Case 1 : No Overlap
  if(r < st || l > end){
    return;
  }

  // Case 2 : Full Overlap
  if(l <= st && end <= r){
    node->val += val; // Update max in this segment
    node->lazy += val; // mark lazy for children
    return;
  }

  // Case 3 : Partial Overlap -> Go Deeper

  // ensure children are updated properly
  push(node);

  int mid = (st + end) >> 1;

  update(node->left, st, mid, l, r, val);
  update(node->right, mid + 1, end, l, r, val);

  node->val = max(node->left->val, node->right->val);

}

// TC = O(N*Log(Range)) = O(N * log(1e9)) = O(N*30)

// SC = O(N*Log(Range))

class MyCalendarThree {
public:
    Node *root;

    const int MIN = 0;
    const int MAX = 1e9;

    MyCalendarThree() {
        root = new Node();
    }
    
    int book(int s, int e) {
        update(root, MIN, MAX, s, e - 1, 1);

        // Root always stores max overlap value
        return root->val;
    }
};
