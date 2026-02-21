#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1;
int arr[maxN];
int seg[4*maxN],lazy[4*maxN];

void build(int i,int l,int r)
{
  if(l == r)
  {
    seg[i] = arr[l];
    return;
  }
  int mid = (l+r) >> 1;
  build(2*i+1,l,mid);
  build(2*i+2,mid+1,r);
  seg[i] = seg[2*i+1] + seg[2*i+2];
}

int query(int i,int st,int end,int l,int r)
{
  if(lazy[i] != 0)
  {
    seg[i] += (r-l+1)* lazy[i];
    if(l != r)
    {
      lazy[2*i+1] += lazy[i];
      lazy[2*i+2] += lazy[i];
    }
    lazy[i] = 0;
  }
  if(l > end || r < st)
  return 0;

  if(l >= st && r <= end)
  return seg[i];

  int mid = (l+r) >> 1;
  return query(2*i+1,st,end,l,mid) + query(2*i+2,st,end,mid+1,r);
}

void update(int i,int st,int end,int l,int r,int val)
{
  //* Pending Update Check
  if(lazy[i] != 0)
  {
    seg[i] += (r-l+1)*lazy[i];
    if(l!=r)
    {
      lazy[2*i+1] += lazy[i];
      lazy[2*i+2] += lazy[i];
    }
    lazy[i] = 0;
  }
  //* Out of Range
  if(l > end || r < st)
  return;

  //* Current Range is Completely within Query Range
  if(l >= st && r <= end)
  {
    //? Update in SegTree & mark its child as pending update in Lazy tree
    seg[i] += (r-l+1) * val;
    if(l!= r)
    {
      lazy[2*i+1] += val;
      lazy[2*i+2] += val;
    }
    return;
  }

  //* Current Range is Partially in Query wRange
  int mid = (l+r) >> 1;
  update(2*i+1,st,end,l,mid,val);
  update(2*i+2,st,end,mid+1,r,val);
  //? Also update the current node
  seg[i] = seg[2*i+1] + seg[2*i+2];
}
