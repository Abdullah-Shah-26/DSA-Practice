#include<bits/stdc++.h>
using namespace std;
//! TC = O(2 * N * N ) // Visiting each node twice approx 
//! SC = O(2 * N ) + O(ceil(LogNbase2))

int arr[4] = {3,1,2,7}; //* N 
int segTree[2*4-1]; //* (N * 2)-1 , keep 2*n to be on safer side

void buildTree(int i, int l, int r)
{
  if(l == r)
  {
    segTree[i] = arr[r]; // or arr[l];
    return;
  }
  int mid = l + (r-l)/2;
  buildTree(2*i+1,l,mid); // Left Child 
  buildTree(2*i+2,mid+1,r); // Right Child
  segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int main()
{
  buildTree(0,0,3);
  for(auto &it :segTree)
  {
    cout << it << " ";
  }
}