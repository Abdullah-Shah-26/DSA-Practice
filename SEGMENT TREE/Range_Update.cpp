#include<bits/stdc++.h>
using namespace std;

vector<int>arr = {1,2,3,4,5};
int n = arr.size();
vector<int>segTree(4*n);
vector<int>Lazy(4*n,0);

// l , r --- range to increase value by val
void updateRange(int i,int st,int end,int l,int r,int val)
{
  // Check if there is a pending Update
  if(Lazy[i] != 0){
    segTree[i] += (end-st+1)*Lazy[i];
    if(st != end) // Node has Left and Right Child -- Postpone updates for them
    { 
      Lazy[2*i+1] += Lazy[i];
      Lazy[2*i+2] += Lazy[i];
    }
    // Update is done
    Lazy[i] = 0;
  }
  // Range is completely outside of l,r
  if(r < st || l > end || st > end)
  return;

  // Range is completly inside of l,r
  if(st >= l && end <= r)
  {
    segTree[i] += (end - st+1 ) * val;
    if(st != end) // It has children that needs to be Lazy Propogated
    {
      Lazy[2*i+1] += val;
      Lazy[2*i+2] += val;
    }
    return;
  }
  // partial Overlap
  int mid = (st+end) >> 1;
  updateRange(2*i+1,st,mid,l,r,val);
  updateRange(2*i+2,mid+1,end,l,r,val);
  segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int QuerySumLazy(int i,int st,int end,int l,int r)
{
  if(Lazy[i]!=0)
  {
    segTree[i] += (end - st + 1) * Lazy[i];
    if(st != end)
    {
      Lazy[2*i+1] += Lazy[i];
      Lazy[2*i+2] += Lazy[i];
    }
    Lazy[i] = 0;
  }

  // Out of Range
  if(r < st || l > end)
  return 0;

  // Completly in Range
  if(st>=l && end<=r)
  {
    return segTree[i];
  }

  // Partially in Range
  int mid = (st + end) >> 1;
  return QuerySumLazy(2*i+1,st,mid,l,r) + QuerySumLazy(2*i+2,mid+1,end,l,r);
}