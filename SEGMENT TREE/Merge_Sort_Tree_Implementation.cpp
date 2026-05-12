#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1;
int arr[maxN];
vector<int>st[4*maxN]; // Array of vector

//! TC = O(NlogN) // Inserting & Merging Step
//! SC = O(NlogN) // LogN levels * N nodes at each level

// si - segment tree idx
// ss - seg tree starting idx
// se - seg tree ending idx
void build(int si, int ss, int se)
{
  if(ss == se)
  {
    st[si].push_back(arr[ss]);
    return;
  } 
  int mid = (ss + se) >> 1;
  build(2*si,ss,mid);
  build(2*si+1,mid+1,se);

  int i = 0, j = 0;
  //* Merge step of merge sort
  while(i < st[2*si].size() && j < st[2*si+1].size())
  {
    if(st[2*si][i] <= st[2*si+1][j])
    st[si].push_back(st[2*si][i]), i++;
    
    else
    st[si].push_back(st[2*si+1][j]), j++;
  }
  //* If one of them is exhausted and other didint 
  while(i < st[2*si].size())
  st[si].push_back(st[2*si][i]), i++;

  while(j < st[2*si+1].size())
  st[si].push_back(st[2*si][j]), j++;
}  
//* qs - query start
//* qe - query end
//* k - condition
int query(int si,int ss, int se,int qs, int qe, int k)
{
  if(ss > qe || se < qs)
  return 0;

  if(ss >= qs && se <= qe)
  {
    //? idx of element which is strictly > k - 1
    int res = upper_bound(st[si].begin(), st[si].end(), k-1) - st[si].begin();
    return res; //* idx also represents no of elements which are < k
  }

  int mid = (ss + se)/2;
  int l = query(2*si,ss,mid,qs,qe,k);
  int r = query(2*si+1,mid+1,se,qs,qe,k);

  return l+r;

}

int main()
{
  int n,q,l,r,k;
  cin>> n >> q;
  for(int i = 1;i <=n;i++)
  {
    cin >> arr[i];
  }
  build(1,1,n);// 1 based indexing
  while(q--)
  {
    cin >> l >> r >> k;
    cout << query(1,1,n,l,r,k) << endl;
  }
}