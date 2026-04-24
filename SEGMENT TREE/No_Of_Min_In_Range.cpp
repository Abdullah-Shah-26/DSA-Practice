#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int mini; // minimum element
  int cnt;  // count of min element in that range
};

class SegTree
{
private:
  vector<Node> tree;
  vector<int> arr;
  int n;

  Node merge(const Node &a, const Node &b)
  {
    if (a.mini < b.mini)
      return a;
    else if (a.mini > b.mini)
      return b;
    else
      return {a.mini, a.cnt + b.cnt};
  }

  void build(int idx, int l, int r)
  {
    if (l == r)
    {
      tree[idx] = {arr[l], 1};
      return;
    }
    int mid = (l + r) >> 1;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);

    tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
  }

  Node query(int idx, int l, int r, int ql, int qr)
  {
    if (l > qr || r < ql)
      return {std::numeric_limits<int>::max(), 0};

    if (l >= ql && r <= qr)
      return tree[idx];

    int mid = (l + r) >> 1;

    Node left = query(2 * idx + 1, l, mid, ql, qr);
    Node right = query(2 * idx + 2, mid + 1, r, ql, qr);

    return merge(left, right);
  }

  void update(int i, int l, int r, int idx, int val)
  {
    if (l == r)
    {
      arr[l] = val;
      tree[i] = {val, 1};
      return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid)
      update(2 * i + 1, l, mid, idx, val);
    else
      update(2 * i + 2, mid + 1, r, idx, val);

    tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
  }

public:
  SegTree(const vector<int> &input)
  {
    arr = input;
    n = arr.size();
    tree.resize(4 * n);
    if (n > 0)
      build(0, 0, n - 1);
  }

  Node getMin(int l,int r)
  {
    return query(0,0,n-1,l,r);
  }

  void setValue(int idx, int val)
  {
    update(0,0,n-1,idx,val);
  }
};

int main()
{
  int n,m;
  cin >> n >> m;

  vector<int>arr(n);
  for(int i = 0;i < n; i++) cin >> arr[i];

  SegTree st(arr);

  for(int j = 0;j < m; j++)
  {

    int t ;
    cin>> t;
    if(t == 1) // point update
    {
      int idx, val;
      cin>> idx >> val;
      st.setValue(idx, val);
    }
    else{
      int l, r;
      cin>> l >> r;
      auto res = st.getMin(l,r-1);
      cout << res.mini << " " << res.cnt << endl; 
    }
  }
}