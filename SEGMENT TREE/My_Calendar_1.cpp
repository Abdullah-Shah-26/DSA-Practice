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

//! In MyCalendar I we query before update → children don't exist → segfault.
class MyCalendar {
public:
  //! Dynamic Segment Tree with lazy propogation
  // TC = O(N log (10^9))
  // SC = O(N log (10^9)) // Atmost these many nodes get created
  struct Node{
  int val;
  int lazy;
  Node* left;
  Node* right;
  Node() : val(0), lazy(0), left(NULL), right(NULL){}
};

void create(Node *node){
  if(!node->left) node->left = new Node();
  if(!node->right) node->right = new Node();
}

void push(Node *node){
  if(node->lazy == 0){
    return;
  }

  if(!node->left){
     node->left = new Node();
  }

  if(!node->right){
    node->right = new Node();
  }

  node->left->val += node->lazy;
  node->right->val += node->lazy;

  node->left->lazy += node->lazy;
  node->right->lazy += node->lazy;

  node->lazy = 0;
}

int query(Node* node, int st, int end,int l,int r){
  if(!node || r < st || end < l) return 0;

  if(l <= st && end <= r){
    return node->val;
  }

  push(node);
  create(node);

  int mid = (st + end) >> 1;

  return max(query(node->left,st,mid,l,r),query(node->right,mid+1,end,l,r));
}

void update(Node* node, int st, int end, int l,int r){
  if(r < st || end < l){
    return;
  }

  if(st >= l && end <= r){
    node->val += 1;
    node->lazy += 1;
    return;
  }

  push(node);
  create(node);

  int mid = (st + end)>> 1;
  update(node->left, st, mid, l, r);
  update(node->right, mid + 1, end, l, r);

  node->val = max(node->left->val, node->right->val);
}

  Node* root;
  int MIN = 0;
  int MAX = 1e9;

    MyCalendar() {
        root = new Node();
    }
    
    bool book(int st, int end) {
        if(query(root, MIN, MAX,st, end-1) >= 1){
          return false;
        }
        update(root, MIN, MAX, st, end - 1);
        return true;
    }
};

